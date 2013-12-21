<?php
	require_once($_SERVER['DOCUMENT_ROOT'] . "/php/register_example/includes/common.php");
	
	function username_link($username)
	{
		return "<a href=\"/php/register_example/user.php?username={$username}\">{$username}</a>";
	}

	function render_user_list()
	{
		$query = "SELECT username, name, surname FROM users;";
		$result = mysql_query($query);
		if (! $result)
		{
			mysql_die(); 
			return 0;
		}
		echo '<table class="users"><tr><td class="usersh">Пользователь</td><td class="usersh">Имя</td><td class="usersh">Фамилия</td></tr>';
		while ( $user = mysql_fetch_array($result) )
		{
			echo 	 "<tr> <td>" . username_link($user['username']) . "</td>"
				."<td>{$user['name']}</td>"
				."<td>{$user['surname']}</td> </tr>";
		}
		return 1;
	}

	function render_session_bar()
	{
	?>
		<table class="userbar"><tr><td class="userbar_whitespace"><a href="/php/register_example/">ОткрытыйИН.рф xD</a></td><td class="userbar_login">
	<?php
		if ( ! isset($_SESSION['username']) ) 
		{	
	?>
		<form action="/php/register_example/" method="POST">
			Логин: <input type="text" class="user_login" name="login"/>
			Пароль: <input type="password" class="user_login" name="passw"/>
			<input type="submit" class="user_login_btn" name="login_btn" value="Войти"/><br />
			<a class="register" href="/php/register_example/register.php">Регистрация</a>
		</form>
	<?php	
		}
		else
		{
			echo username_link($_SESSION['username']);
	?>
		<br /><a class="logout" href="/php/register_example/index.php?action=logout">Выход</a>
	<?php
		}
	?>
		</td></tr></table>
	<?php
	}


	function render_register_form()
	{
		if (isset($_SESSION['username']))
		{
			$user = get_user_info($_SESSION['username']);
			if ($user == 0) 
				unset($user);
		}
	?>
		<form class="registerform" method="POST" action="<?php echo $_SERVER['PHP_SELF']; ?>">
		<table class="registertable">
			<tr><th class="registerth">Идентификатор пользователя (<font color="red">*</font>): </th>
		    	<td><input class="registerinput" name="username" type="text" value="<?php if (isset($user)) echo $user['username']; ?>" /></td></tr>
	<?php			if (!isset($user)) { ?>
			<tr><th class="registerth">Пароль (<font color="red">*</font>):</th>
			<td><input class="registerinput" name="password" type="password" value="<?php if (isset($user)) echo $user['password']; ?>" /></td></tr>
	<?php			}	?>
			<tr><th class="registerth">E-Mail (<font color="red">*</font>):</th>
			<td><input class="registerinput" name="email" type="email" value="<?php if (isset($user)) echo $user['email']; ?>" /></td></tr>
			<tr><th class="registerth">Имя:</th>
			<td><input class="registerinput" name="name" type="text" value="<?php if (isset($user)) echo $user['name']; ?>" /></td></tr>
			<tr><th class="registerth">Фамилия:</th>
			<td><input class="registerinput" name="surname" type="text" value="<?php if (isset($user)) echo $user['surname']; ?>" /></td></tr>
			<tr><th class="registerth">О себе:</th>
			<td><textarea class="comment" name="comment"><?php if (isset($user)) echo $user['comment']; ?></textarea></td></tr>
			<tr><td></td>
			<td><input class="registerbtn" name="sendRegisterData" type="submit" value="Зарегистрировать" /></td></tr>
		</table>
		</form>
	<?php			
		return 0;
	}

	function render_congrats_newbie()
	{
	?>
		<p><h3>Поздравляем, %username!%, ты успешно зарегестрировался!</h3>
		Твои регистрационные данные:</p>
	<?php
	}

	function render_user_info($username)
	{
		$user = get_user_info($username);
		if ($user == 0)
		{
	?>
			<p><h3>Ошибка!</h3>Пользователь <?php echo $username; ?> не найден.</p>
	<?php
			return 0;
		}
	?>
		<table class="userinfo">
			<tr><td>Имя пользователя:</td>
			<td><?php echo $user['username']; ?></td>
			<tr><td>Имя:</td>
			<td><?php echo $user['name']; ?></td>
			<tr><td>Фамилия:</td>
			<td><?php echo $user['surname']; ?></td>
			<tr><td>E-Mail:</td>
			<td><?php echo $user['email']; ?></td>
			<tr><td>О себе:</td>
			<td><?php echo $user['comment']; ?></td>
		</table>
	<?php
		return 1;
	}

	function render_incorrect_register_data()
	{
	?>
		<p><h3>Некорректные данные в форме регистрации!<h3></p>
	<?php
	}
// Ебануцца, надо раскидать все в инклуды
?>
