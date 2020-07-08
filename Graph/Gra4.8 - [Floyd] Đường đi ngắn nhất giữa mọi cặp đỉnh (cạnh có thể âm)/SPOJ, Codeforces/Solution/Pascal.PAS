const     INP        =        '' ;
          OUT        =        '' ;

          maxn       =        100      ;
          maxc       =        10000000 ;

var       n , m , cau_hoi :  integer ;
          a          :       array[1..maxn,1..maxn] of longint ;
          trace      :       array[1..maxn,1..maxn] of byte    ;
          fi , fo    :       text    ;

procedure answer ;
var
      i , j , u , v , pt , loai : integer ;
      l : array[1..maxn] of integer ;

      procedure truy_vet( u , v : integer ) ;
      var
           k : integer ;
      begin
           k := trace[u,v] ;
           if k = 0 then begin
              inc( pt )  ;
              l[pt] := v ;
              exit ;
           end ;
           truy_vet( u , k ) ;
           truy_vet( k , v ) ;
      end ;

begin
     for i := 1 to cau_hoi do begin
         read( fi , loai , u , v ) ;
         if loai = 0 then writeln( fo , a[u,v] ) { cau hoi loai 0 }
         else
             { cau hoi loai 1 }
             if a[u,v] < 0 then writeln( fo , -1 )
             else begin
                 pt   := 1 ;
                 l[1] := u ;
                 truy_vet( u , v ) ;

                 write( fo , pt )  ;
                 for j := 1 to pt do write( fo , ' ', l[j] ) ;
                 writeln( fo ) ;
             end ;
     end ;
end ;

procedure process ;
var
     k , u,  v : longint ;
begin
     for k := 1 to n do { Floyd }
         for u := 1 to n do
             for v := u + 1 to n do
                 if a[u,v] > a[u,k] + a[k,v] then begin
                    a[u,v] := a[u,k] + a[k,v] ;
                    a[v,u] := a[u,v] ;
                    trace[u,v] := k  ;
                    trace[v,u] := k  ;
                 end ;

     for u := 1 to n do
         for v := 1 to n do
             if a[u,v] = maxc then a[u,v] := -1 ; { Khong ton tai duong di }
end ;

procedure nhapdl ;
var
      i , j,  u , v , val : longint ;
begin
     read( fi , n , m , cau_hoi ) ;
     for i := 1 to n do
         for j := 1 to n do a[i,j] := maxc ;
     for i := 1 to m do begin
         read( fi , u , v , val ) ;
         a[u,v] := val ;
         a[v,u] := val ;
     end ;

     for i := 1 to n do a[i,i] := 0 ;
end ;

procedure mofile ;
begin
     assign( fi , INP ) ; reset( fi )   ;
     assign( fo , OUT ) ; rewrite( fo ) ;
end ;

procedure dongfile ;
begin
     close( fi ) ; close( fo ) ;
end ;

BEGIN
     mofile   ;
     nhapdl   ;
     process  ;
     answer   ;
     dongfile ;
END.