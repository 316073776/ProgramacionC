<html>
<head>
<title>Prueba de Arreglos</title>
</head>
<body text="#ffffff" link="#33ccff" vlink="#ff99ff"
bgcolor="gray">
<br><br>

<?php
 
    function Insercion($numeros,$arreglo_tamano)
    {
 
        for ($var1 = 1; $var1 < $arreglo_tamano; $var1++)
        {
                 $indice = $numeros[$var1];
                 $aux = $var1 - 1;
                 while ($aux >= 0 && $numeros[$aux] > $indice)
                 {
                          $numeros[$aux + 1] = $numeros[$aux];
                          $aux--;
                 }
 
                 $numeros[$aux + 1] = $indice;
        }
 
        return $numeros;
    }
 
    function Seleccion($arreglo,$tamano_arreglo)
    {
        for ($aux=0; $aux<$tamano_arreglo-1; $aux++)
    {
              $minimo=$aux;
              for($aux2=$aux+1; $aux2<$tamano_arreglo; $aux2++)
                    if($arreglo[$minimo] > $arreglo[$aux2])
                       $minimo=$aux2;
              $aux3=$arreglo[$minimo];
              $arreglo[$minimo]=$arreglo[$aux];
              $arreglo[$aux]=$aux3 ;
        }
 
      return $arreglo;
    }

    function Burbuja($arreglo,$tamano_arreglo)
    {
        for($aux=1; $aux<$tamano_arreglo; $aux++)
        {
                for($aux2=0; $aux2<$tamano_arreglo-$aux1; $aux2++)
                {
                        if($arreglo[$aux2]>$arreglo[$aux2+1])
                        {
                            $num=$arreglo[$aux2+1]; 
                            $arreglo[$aux2+1]=$arreglo[$aux2]; 
                            $arreglo[$aux2]=$num;
                        }
                }
        }
 
      return $arreglo;
    }

    function quicksort($arreglo, $izq, $der)
    {
        $aux1 = $izq;
        $aux2 = $der;
        $centro = $arreglo[ ($izq + $der) /2 ];

    do{
        while( ($arreglo[$aux1] < $centro) && ($aux2 <= $der) )
        {
            $aux1++;
        }
 
        while( ($centro < $arreglo[$aux2]) && ($aux2 > $izq) )
        {
            $aux2--;
        }
 
        if( $aux1 <= $aux2 )
        {
            $auxiliar = $arreglo[$aux1]; 
            $arreglo[$aux1] = $arreglo[$aux2]; 
            $arreglo[$aux2] = $auxiliar;
            $aux1++;  
            $aux2--;
        }
 
    }while( $aux1 <= $aux2 );
 
    if( $izq < $aux2 )
        quicksort( $arreglo, $izq, $aux2 );
    if( $aux1 < $der )
        quicksort( $arreglo, $aux1, $der );
 
        return $arreglo;
    }

    function main()
    {
        echo "<h2>Ordenamiento por incersi&oacute;n: \n</h2>";
        echo "<h3>Vector Original</h3>";
        $VectorA=array(5,4,3,2,1);
        for($i=0; $i<sizeof($VectorA); $i++)
            echo $VectorA[$i]."\n";
 
		echo "</br></br><h3>Vector Ordenado</h3>";
        $VectorB=Insercion($VectorA,sizeof($VectorA));
        for($i=0; $i<sizeof($VectorB) ;$i++)
            echo $VectorB[$i]."\n";



        echo "<h2>Ordenamiento por selecci&oacute;n: \n</h2>";
        echo "<h3>Vector Original</h3>";
        $VectorC=array(5,4,3,2,1);
        for($i=0; $i<sizeof($VectorC); $i++)
            echo $VectorC[$i]."\n";

        echo "</br></br><h3>Vector Ordenado</h3>";
        $VectorD=Seleccion($VectorC,sizeof($VectorC));
        for($i=0; $i<sizeof($VectorD); $i++)
            echo $VectorD[$i]."\n";



        echo "<h2>Ordenamiento por burbuja: \n</h2>";
        echo "<h3>Vector Original</h3>";
        $VectorE=array(5,4,3,2,1);
        for($i=0; $i<sizeof($VectorE); $i++)
            echo $VectorE[$i]."\n";

        echo "</br></br><h3>Vector Ordenado</h3>";
        $VectorF=Burbuja($VectorE,sizeof($VectorE));
        for($i=0; $i<sizeof($VectorF); $i++)
            echo $VectorF[$i]."\n";



        echo "<h2>Ordenamiento Quicksort: \n</h2>";
        echo "<h3>Vector Original</h3>";
        $VectorG=array(5,4,3,2,1);
        for($i=0; $i<sizeof($VectorG); $i++)
            echo $VectorG[$i]."\n";

        echo "</br></br><h3>Vector Ordenado</h3>";
        $VectorH=quicksort($VectorG, 0, sizeof($VectorG)-1);
        for($i=0; $i<sizeof($VectorH); $i++)
            echo $VectorH[$i]."\n";
 
    }
 
    main();
?>

</body>
</html>


