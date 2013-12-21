<?php
	class MyClass 
	{
		var $a, $b;

		function __construct()
		{
			$this->a=5;
			$this->b=5;
		}

		function setA($n_a)
		{
			$this->a = $n_a;
		}

		function setB($n_b)
		{
			$this->b = $n_b;
		}

		function echoSum()
		{
			echo $this->a + $this->b;
		}
	}


	$obj = new MyClass;

	$obj->echoSum();

	$obj->setA(5);
	$obj->setB(15);
	$obj->echoSum();
?>
