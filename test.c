function factorial(i: integer) : integer {
          var j: integer;
          j := i;
          if (i <= 0)
          {
              j := 1;
          }
          else
          {
              i := factorial(i - 1);
              j := j * i;
          }
          return j;
}

function Main() : integer {
	  var a: integer;
	  a := factorial(5);
          a := a /. 2;
	  return a;
}

