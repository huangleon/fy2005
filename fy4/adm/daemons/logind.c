// logind.c

#define MAX_DUMMY 16 //¿ÉÒÔÔÊĞí¶àÉÙdummy
#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_DBASE;

int wiz_lock_level = WIZ_LOCK_LEVEL;
int new_user_lock = NEW_USER_LOCK;
int dummy_num = MAX_DUMMY;

#ifdef MAX_USERS
int max_ppl = MAX_USERS;
#endif

string L_IP = "216.101.216.55555555";
string Rname;
string *banned_name = ({
	"Äã", "Äã", "ÎÒ", "Ëû", "Ëı", "Ëü", "Ëü",
	"·çÔÆ","°¢Ìú", "·çÔÆ£É£É","·çÔÆ¢ò", "ºº×å",
	"Ãç×å",  "Âú×å","ÃÉ¹Å×å","·çÔÆ£É£É£É","·çÔÆ¢ó",
	"ÏµÍ³", "ºËĞÄ", "ÏµÍ³ºËĞÄ", "·çÔÆ2005", "·çÔÆ£µ","·çÔÆ£²£°£°£µ"
	"²Ù", "ÈÕ", "£æ£õ£ã£ë","£Æ£Õ£Ã£Ë","£Æ£õ£ã£ë",
});
string *banned_id= ({
	"chat", "new", "fy", "rumor", "tell", "none", "reboot",
	"shutdown","core", "fymud","mud", "fuck", "public", "tianji",
	"afa", "amao", "mei", "huang",  "dick",  "shit","cao","cunt","slut",
	"all", "tufei", "peng" , "here","tie","fengyun",
	"corpse", "skeleton", "stone", "rock", "door", "ghost", "keeper",
	"priest", "master", "table", "flower", "grass", "basket", "bag",
	"box", "boy", "kid", "girl", "sword", "blade", "ironfist", "whip",
	"hammer", "axe", "spear", "staff","cor", "fish", "shrimp", "ant", 
	"butterfly", "rat", "cat", "snake", "tiger", "bear", "wolf", "river", "hyena"
	"liu","shiwei","huwei","bodyguard","spirit",
});

string *start_loc = ({
	AREA_FY"fqkhotel",
	AREA_CHENXIANG"cag",
	AREA_GUANWAI"inn",
	AREA_LAOWU"inn",
});

private void get_encoding(string arg, object ob);
private void get_id(string arg, object ob);
private void get_passwd(string pass, object ob);
private void read_msg(string arg, object ob);
private void get_resp(string arg, object ob);
private void confirm_id(string yn, object ob);
private object make_body(object ob);
private int valid_wiz_login(string id,string ip);
private void init_new_player(object user);
private void confirm_relogin(string yn, object ob, object user);
private void get_verify_code(string an,object ob,int answer,int chs);
private void get_name(string arg, object ob);
private void new_password(string pass, object ob);
private void confirm_password(string pass, object ob);
private void get_email(string email, object ob);
private void get_gender(string gender, object ob, object user);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);
int check_legal_password(object ob,string arg);
int set_attribute(object user,int tol, int fle, int agi, int dur, int intt, int str, int con, int spi, int per, int cor, int cps, int kar);
int cphirdir(string dirstr, string newdirstr);
string random_name();
void logon_write(string str);

void create() {
	seteuid(getuid());
}

void logon(object ob) {

	// Before we do all this, see if this installation is legal and not expired
/*
	if(SECURITY_D->check_illegal(L_IP)) {
		shutdown(0);
	}
	if(SECURITY_D->check_illegal2()) {
		shutdown(0);
	}

*/
	if (BAN_D->is_banned(query_ip_name(ob))  ||
			BAN_D->is_banned(query_ip_number(ob))) {
		write("¶Ô²»Æğ£¬ÄúµÄµØÖ·±»¾Ü¾øÁ¬Ïß¡£
ÇëÉêÇë¼ÓÈë ¾­µä·çÔÆµÄQQÈº 132539787 Í¶Ëß²¢¿ªÍ¨ÄãµÄIP¶Î¡£\n");
		destruct(ob);
		return;
	}

	cat(WELCOME) ;
	get_encoding("", ob);
}

private void get_encoding(string arg, object ob) {
	string str;
	object *usr;
	int i, wiz_cnt, ppl_cnt, login_cnt;
	int log_num, extra_num;
	
	if(arg == "0" || arg == "£°") {
		ob->set_temp("char_encoding", "gb");
	} else if(arg == "1" || arg == "£±") {
		ob->set_temp("char_encoding", "big5");
	} else {
		str = "¹ú±êÂë";
		write("    0) " + str + "(" + ENCODE_D->gbTobig5(str) + ") GB\n");
		str = "´óÎåÂë";
		write("    1) " + str + "(" + ENCODE_D->gbTobig5(str) + ") BIG5\n");
		str = "ÇëÑ¡ÔñÄúÊ¹ÓÃµÄÄÚÂë";
		write(str + "(" + ENCODE_D->gbTobig5(str) + "): ");
		input_to((: get_encoding :), ob);
		return;
	}
	write("\n\n");
	UPTIME_CMD->main();
	usr = users();
	wiz_cnt = 0;
	ppl_cnt = 0;
	login_cnt = 0;
	for(i=0; i<sizeof(usr); i++) {
		if( !environment(usr[i]) ) login_cnt++;
		else if( wizardp(usr[i]) && !usr[i]->query("wiz_invis")) wiz_cnt++;
		else ppl_cnt++;
	}
	write(sprintf(YEL"Ä¿Ç°¹²ÓĞ%sÎ»ÈËÊ¿ÕıÔÚÓÎÏ·ÖĞ¡£\n"
	"ÆäÖĞÓĞ%sÎ»¹ÜÀíÔ±¡¢%sÎ»±¾µØÍæ¼Ò¡¢¼°%sÎ»³¢ÊÔÕß¡£\n\n" NOR,
	chinese_number(WHO_D->query_num()), chinese_number(wiz_cnt),
	chinese_number(ppl_cnt), chinese_number(login_cnt)));

//max_dummy
	if (NETBAR_D->netbar_stat()) {
		
		for(i=0;i<sizeof(usr);i++)
		if (ob!=usr[i]) {
			if	(query_ip_name(ob)==query_ip_name(usr[i]))
				log_num = log_num+1;			
		}			
		
		if  (
				//µ÷ÓÃnetbarº¯Êı£¬ÉèÖÃ²»ÊÜÏŞÖÆµÄÕ¾µã
				!NETBAR_D->is_netbar(query_ip_number(ob))
				&&!NETBAR_D->is_netbar(query_ip_name(ob))
			)
			extra_num =1;
		else
			extra_num =2;
		if (log_num >= (dummy_num+1)*extra_num )
		{
			write(HIR+"ÄãÖ»ÔÊĞíÍ¬Ê±µÇÂ½" + chinese_number((dummy_num+1)*extra_num) + "¸öID£¬ÇëÍË³öÆäËûÕÊºÅÔÙÊÔ¡£\n"+NOR);
			destruct(ob);
			return;
		}
		else
		{       
			log_num= (dummy_num+1)*extra_num - log_num -1;
			write("ÄúËùÔÚµÄµØÖ·("+YEL+query_ip_number(ob)+NOR")»¹ÔÊĞíÓĞ"YEL+chinese_number(log_num)+NOR"Î»Íæ¼ÒÁ¬Ïß¡£\n\n");
		}
	}
	
	write("ÄúµÄÓ¢ÎÄÃû×Ö£º");
	input_to( (: get_id :), ob);
}

private void get_id(string arg, object ob)
{
	object ppl,*usr;
	int i;
	mixed alle;

	arg = lower_case(arg);
	if( !check_legal_id(arg))
	{
		write("ÄúµÄÓ¢ÎÄÃû×Ö£º");
		input_to((:get_id:), ob);
		return;
	}

#ifdef MAX_USERS
	if( (string)SECURITY_D->get_status(arg)=="(player)"
		&& sizeof(users()) > max_ppl)

	{
		ppl = find_body(arg);
		// Only allow reconnect an interactive player when MAX_USERS exceeded.
		if( !ppl || !interactive(ppl) )
		{
			write("¶Ô²»Æğ£¬"+MUD_NAME+"µÄÊ¹ÓÃÕßÒÑ¾­Ì«¶àÁË£¬Çë´ı»áÔÙÀ´¡£\n");
			destruct(ob);
			return;
		}
	}
#endif

	if( wiz_level(arg) < wiz_lock_level && SERV != LOCAL )
	{
		write("¶Ô²»Æğ£¬" + MUD_NAME +
			  "Ä¿Ç°ÕıÔÚÎ¬»¤Ö®ÖĞ£¬ÇëÉÔºòÔÙÁ¬Ïß¡£\n");
		destruct(ob);
		return;
	}

	if (uptime()< 300 && !wiz_level(arg) && SERV != LOCAL ) {
		write("·çÔÆÏµÍ³ÕıÔÚ³õÊ¼»¯£¬ÇëÔÚÎå·ÖÖÓºóÔÙµÇÂ½¡£\n");
		destruct(ob);
		return;
	}
		
	if( (string)ob->set("id", arg) != arg )
	{
		write("Failed setting user name.\n");
		destruct(ob);
		return;
	}
// toomany guets nowdays
	if( arg=="guesttttttttt" )
	{
		// If guest, let them create the character.
		confirm_id("Yes", ob);
		return;
	}
	else if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 )
	{
//		write("a"+file_size(ob->query_save_file() + __SAVE_EXTENSION__));
		if( ob->restore() )
		{
			if (wiz_level(arg)) {
				write("´ËÓ¢ÎÄÃû×ÖÒÑ±»Ê¹ÓÃ£¬ÇëÊäÈë´ËÕÊºÅµÄÃÜÂë£º");
				input_to((:get_passwd:), 1, ob);
			} else
			{
				write("´ËÓ¢ÎÄÃû×ÖÒÑ±»Ê¹ÓÃ£¬ÇëÊäÈë´ËÕÊºÅµÄÃÜÂë£º");
				input_to((:get_passwd:), 1, ob);
/*				alle="/feature/nada.c"->my_number();
				write("\n");
				write(alle[0]);
				write("\nÇëÊäÈëÒÔÉÏĞ£ÑéÂë£º");
				input_to((:get_verify_code:),1,ob,alle[1],1);  */ //  add by ldb ¹Ø±Õ·³ÈËµÄÊı×ÖĞ£Ñé 
			}                            
			return;                
		}
		write("ÄúµÄÈËÎï´¢´æµµ³öÁËÒ»Ğ©ÎÊÌâ£¬ÇëÀûÓÃ guest ÈËÎïÍ¨ÖªÎ×Ê¦´¦Àí¡£\n");
		destruct(ob);
		return;
	}
	if(new_user_lock)
	{
		write("ÏÖÔÚ·çÔÆ²»½ÓÊÜĞÂµÄÈËÎï£¬ÇëÉÔºòÔÙ´´ÔìĞÂµÄÈËÎï¡£\n");
		destruct(ob);
		return;
	}
	usr = filter_array(children(LOGIN_OB), (: interactive :));
	i = sizeof(usr);
	while (i--)
		if (usr[i] != ob && usr[i]->query("id") == arg)
			break;
	if (i >= 0) {
		write("ÓĞÆäËûÍæ¼ÒÕıÔÚÊ¹ÓÃÕâ¸ö ID£¬ÇëÖØĞÂÊäÈë¡£\n");
		write("ÄúµÄÓ¢ÎÄÃû×Ö£º");
		input_to((:get_id:), ob);
		return;
	}
	write("Ê¹ÓÃ " + (string)ob->query("id") +
		  "\nÕâ¸öÃû×Ö½«»á´´ÔìÒ»¸öĞÂµÄÈËÎï£¬ÄúÈ·¶¨Âğ(y/n)£¿");
	input_to( (: confirm_id :), ob);
}


private void get_verify_code(string an,object ob,int answer,int chs)
{
	int ans;
	if( sscanf(an, "%d", ans)==1 ) {
		if( ans==answer ) {
			if (chs == 1)
			{
				write("´ËÓ¢ÎÄÃû×ÖÒÑ±»Ê¹ÓÃ£¬ÇëÊäÈë´ËÕÊºÅµÄÃÜÂë£º");
				input_to((:get_passwd:), 1, ob);
				return;
			}
		if (chs == 2) {
	write( @TEXT
[37m
·çÔÆÊÇÒ»¸öÒÔ¹ÅÁúĞ¡ËµÎª±³¾°µÄÊÀ½ç£¬ÇëÄúÏëÒ»¸öÓĞÆøÖÊ£¬ÓĞ¸öĞÔ
µÄÖĞÎÄÃû×Ö´ú±íÄãµÄÈËÎï£¬´ËÃû×Ö´´Á¢ºó½«²»ÄÜÔÙ¸ü¸Ä¡£

Çë²»ÒªÊ¹ÓÃ¹ÅÁúĞ¡ËµÖĞÈËÃû»òÕßÒ»Ğ©Í¨Ë×µÄ³ÆºôÒÔÃâÒıÆğ»ìÏı£¬¸ü
²»ÒªÊ¹ÓÃ¾ßÓĞ²»Á¼º¬Òå»òÎêÈèĞÔµÄ´Ê£¬Èç·¢ÏÖ´ËÀàÇé¿ö£¬·çÔÆ¹¤×÷
×é±£Áô¸ü¸ÄÒÔÖÁÉ¾³ı¸ÃÈËÎïµÄÈ¨Àû¡£

[31m
Èç¹ûÄãÓĞÀ§ÄÑÊäÈëÖĞÎÄÃû×Ö£¬ÇëÖ±½ÓÇÃ»Ø³µ¼ü£Û£Ò£Å£Ô£Õ£Ò£Î£İ¡£
[32m
TEXT
		);
					write("ÄúµÄÖĞÎÄÃû×Ö£º");
					input_to((:get_name:), ob);
				return;
			}
		}
	}
	write("Ğ£ÑéÎ´ÔøÍ¨¹ı¡£\n");
	destruct(ob);
	return;
}

private void get_passwd(string pass, object ob)
{
	string my_pass;
	object user;

	my_pass = ob->query("password");
	if( crypt(pass, my_pass) != my_pass )
	{
		write("ÃÜÂë´íÎó£¬ÖĞ¶ÏµÇÂ½³ÌĞò£¡\n");
		log_file("ATTEMPT_LOGIN",sprintf("FAILED: %s tried to login from %s\n",
										 ob->query("id"), query_ip_number(ob)));
		destruct(ob);
		return;
	}

	// Check if we are already playing.
	user = find_body(ob->query("id"));
	if (user)
	{
		if(!user->query_temp("successful_login")) {
			destruct(user);
		} else {

		if( user->query_temp("netdead") )
		{
			reconnect(ob, user);
			return;
		}

		write("\nÄúÒª½«ÁíÒ»¸öÁ¬ÏßÖĞµÄÏàÍ¬ÈËÎï¸Ï³öÈ¥£¬È¡¶ø´úÖ®Âğ£¿£¿(y/n)");
		input_to((:confirm_relogin:), ob, user);
		return;
		}
	}

	if( objectp(user = make_body(ob)) )
	{
		if( user->restore() )
		{
			log_file( "USAGE", sprintf(
				"%s loggined from %s (%s)\n",
				user->query("id"),query_ip_number(ob), ctime(time()) ) );
			log_file("STAT", sprintf(
				"ON %s %s %d %d %d %d %d %d %s\n",
				user->query("id"),user->query("name"),
				user->query("combat_exp"), user->query("deposit"),
				user->query("potential"),user->query("TASK"),
				user->query("mud_age"), user->query("QUEST"),
				ctime(time()) ) );
			if(time()-(int)user->query("kickout_time") < 3600)
			{
				write("ÄãÏÖÔÚÃ»ÓĞ½øÈë·çÔÆµÄÈ¨Àû£¬ÇëÔÚ"+ (60-(time() - user->query("kickout_time"))/60) + "·ÖÖÓºóÔÙÁªÏß¡£\n");
				destruct(user);
				destruct(ob);
				return;
			}
			enter_world(ob, user);
			return;
		}
		else  destruct(user);
	}
	write("ÇëÄúÖØĞÂ´´ÔìÕâ¸öÈËÎï¡£\n");
	confirm_id("y", ob);
}

private void confirm_relogin(string yn, object ob, object user)
{
	object old_link;

	if(!objectp(user)) {
		write("ÁíÒ»¸öÁ¬ÏßÖĞµÄÏàÍ¬ÈËÎïÒÑ²»´æÔÚ£¬ÇëÖØĞÂÁ¬Ïß¡£\n");
		destruct(ob);
		return;
	}

	if(yn=="") {
		write("\nÄúÒª½«ÁíÒ»¸öÁ¬ÏßÖĞµÄÏàÍ¬ÈËÎï¸Ï³öÈ¥£¬È¡¶ø´úÖ®Âğ£¿(y/n)");
		input_to((:confirm_relogin:), ob, user);
		return;
	}

	if(yn[0]!='y' && yn[0]!='Y') {
		write("ºÃ°É£¬»¶Ó­ÏÂ´ÎÔÙÀ´¡£\n");
		destruct(ob);
		return;
	} else {
		tell_object(user, "ÓĞÈË´Ó±ğ´¦( " + query_ip_name(ob)
					+ " )Á¬ÏßÈ¡´úÄãËù¿ØÖÆµÄÈËÎï¡£\n");
		log_file("USAGE", sprintf("%s replaced by %s (%s)\n",
								   user->query("name"),
								   query_ip_number(ob), ctime(time()) ) );
	}

	// Kick out tho old player.
	old_link = user->query_temp("link_ob");
	if( old_link )
	{
		exec(old_link, user);
		destruct(old_link);
	}

	reconnect(ob, user);
}

private void confirm_id(string yn, object ob)
{
	mixed alle;
	if( yn=="" )
	{
		write("Ê¹ÓÃÕâ¸öÃû×Ö½«»á´´ÔìÒ»¸öĞÂµÄÈËÎï£¬ÄúÈ·¶¨Âğ(y/n)£¿");
		input_to((:confirm_id:), ob);
		return;
	}

	if( yn[0]!='y' && yn[0]!='Y' )
	{
		write("ºÃ°É£¬ÄÇ÷áÇëÖØĞÂÊäÈëÄúµÄÓ¢ÎÄÃû×Ö£º");
		input_to((:get_id:), ob);
		return;
	}
			alle="/feature/nada.c"->my_number();
			write("\n");
			write(alle[0]);
			write("\nÇëÊäÈëÒÔÉÏĞ£ÑéÂë£º");
			input_to((:get_verify_code:),1,ob,alle[1],2);       

	return;                                              
}

private void get_resp(string arg, object ob)
{
	if( arg=="" )
	{
		write("ÄúÂúÒâ(y)²»ÂúÒâ(n)Õâ¸öÖĞÎÄÃû×Ö£¿");
		input_to((:get_resp:), ob);
		return;
	}

	if( arg[0]=='y' || arg[0]=='Y' )
	{
	//	printf("%O\n", ob);
		ob->set("name", Rname);
		write("[37m
ÃÜÂë±ØĞë×îÉÙÁù¸ö×Ö·û£¬ÇÒ°üº¬´óĞ¡Ğ´×ÖÄ¸ºÍÊı×Ö»ò±êµã
	[1;31mÇëÉè¶¨ÄúµÄÃÜÂë£º[0;32m\n");
		input_to((:new_password:), 1, ob);
		return;
	}
	else if( arg[0]=='n' || arg[0]=='N')
	{
		Rname = random_name();
		write("ÄúÂúÒâ(y)²»ÂúÒâ(n)Õâ¸öÖĞÎÄÃû×Ö£¿");
		printf( HIY" -- %s £º"NOR, Rname);
		input_to((:get_resp:), ob);
		return;
	}
	else
	{
		write("¶Ô²»Æğ£¬ÄúÖ»ÄÜÑ¡ÔñÂúÒâ(y)²»ÂúÒâ(n)£º ");
		input_to((:get_resp:), ob);
		return;
	}
}

private void get_name(string arg, object ob)
{
	string name;
	if( arg =="")
	{
	Rname = random_name();
		write("¿´À´ÄúÒª¸öËæ»ú²úÉúµÄÖĞÎÄÃû×Ö£®£®\n");
		write("ÄúÂúÒâ(y)²»ÂúÒâ(n)Õâ¸öÖĞÎÄÃû×Ö£¿");
		printf( HIY" -- %s £º"NOR, Rname);
		input_to((:get_resp:), ob);
	}
	else
	{
		if(ob->query_temp("char_encoding") == "big5") {
			arg = ENCODE_D->big5Togb(arg);
		}
		if( !check_legal_name(arg) )
		{
			write("ÄúµÄÖĞÎÄÃû×Ö£º");
			input_to((:get_name:), ob);
			return;
		}

		printf("%O\n", ob);
		ob->set("name", arg);
		write("ÇëÉè¶¨ÄúµÄÃÜÂë£º");
		input_to((:new_password:), 1, ob);
	}
}

private void new_password(string pass, object ob)
{
	write("\n");
	if( !check_legal_password(ob,pass))
	{
		input_to((:new_password:), 1, ob);
		write("ÇëÉè¶¨ÄúµÄÃÜÂë£º");
		return;
	}
	ob->set("password", crypt(pass,0) );
	write("ÇëÔÙÊäÈëÒ»´ÎÄúµÄÃÜÂë£¬ÒÔÈ·ÈÏÄúÃ»¼Ç´í£º");
	input_to((:confirm_password:), 1, ob);
}

private void confirm_password(string pass, object ob)
{
	string old_pass;
	write("\n");
	old_pass = ob->query("password");
	if( crypt(pass, old_pass)!=old_pass ) {
		write("ÄúÁ½´ÎÊäÈëµÄÃÜÂë²¢²»Ò»Ñù£¬ÇëÖØĞÂÉè¶¨Ò»´ÎÃÜÂë£º");
		input_to((:new_password:), 1, ob);
		return;
	}
	write("£¨Èç¹ûÒÔºóÒÅÊ§»òÍü¼ÇÁËÃÜÂë£¬Ö»ÓĞÆ¾´Ëµç×ÓÓÊ¼şµØÖ·²ÅÄÜ»Ö¸´£©\n");
	write("ÄúµÄµç×ÓÓÊ¼şµØÖ·£º");
		input_to((:get_email:),  ob);
}

private void get_email(string email, object ob)
{
	object user;
	ob->set("email", email);

	// If you want do race stuff, ask player to choose one here, then you can
	// set the user's body after the question is answered. The following are
	// options for player's body, so we clone a body here.
	ob->set("body", USER_OB);
	if( !objectp(user = make_body(ob)) )
		return;

	write("ÄúÒª°çÑİÄĞĞÔ(m)µÄ½ÇÉ«»òÅ®ĞÔ(f)µÄ½ÇÉ«£¿");
	input_to((:get_gender:), ob, user);
}

private void get_gender(string gender, object ob, object user)
{
	if( gender=="" )
	{
		write("ÄúÒª°çÑİÄĞĞÔ(m)µÄ½ÇÉ«»òÅ®ĞÔ(f)µÄ½ÇÉ«£¿");
		input_to((:get_gender:), ob, user);
		return;
	}

	if( gender[0]=='m' || gender[0]=='M' )
		user->set("gender", "ÄĞĞÔ");
	else if( gender[0]=='f' || gender[0]=='F' )
		user->set("gender", "Å®ĞÔ" );
	else
	{
		write("¶Ô²»Æğ£¬ÄúÖ»ÄÜÑ¡ÔñÄĞĞÔ(m)»òÅ®ĞÔ(f)µÄ½ÇÉ«£º");
		input_to((:get_gender:), ob, user);
		return;
	}
	
	// New login bypass race
	
	user->set("national", "ºº×å");
	log_file( "USAGE", sprintf("%s was created from %s (%s)\n",
		user->query("id"),query_ip_name(ob), ctime(time()) ) );
	init_new_player(user);
	enter_world(ob,user);
	return;
		
}


object make_body(object ob)
{
	string err;
	object user;
	int n;

	user = new(ob->query("body"));
	if(!user)
	{
		write("ÏÖÔÚ¿ÉÄÜÓĞÈËÕıÔÚĞŞ¸ÄÊ¹ÓÃÕßÎï¼şµÄ³ÌÊ½£¬ÎŞ·¨½øĞĞ¸´ÖÆ¡£\n");
		write(err+"\n");
		return 0;
	}
	seteuid(ob->query("id"));
	export_uid(user);
	export_uid(ob);
	seteuid(getuid());
	user->set("id", ob->query("id"));
	user->set_name( ob->query("name"), ({ ob->query("id")}) );
	return user;
}

private void init_new_player(object user)
{
	string national;
	user->set("title", "ÆÕÍ¨°ÙĞÕ");
	user->set("birthday", time() );
	user->set("potential", 500);
	user->set("score", 0);
	set_attribute(user,10,10,10,10,10,10,10,10,5+random(15),10,10,10);
	
	user->setup();
	user->set("food", user->max_food_capacity());
	user->set("water", user->max_water_capacity());
	user->set("env/wimpy", 50);
	user->set("env/equip_msg",2);
	user->set("combat_exp",2000);
	user->set("channels", ({ "chat","fy","new","info","announce",
							 "vote","bangtalk","teamtalk" }) );
}

varargs void enter_world(object ob, object user, int silent)
{
	object cloth, room;
	mixed info;
	string id;
	string mailfile;
	int laston;
	
	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);
	exec(user, ob);
	user->set_temp("char_encoding", ob->query_temp("char_encoding"));

	write(CLR + "Ä¿Ç°È¨ÏŞ£º" + wizhood(user) + "\n");
	user->setup();

	// Add by annie. Block bugged account.
	if(ob->query("blocked") && !wizardp(user))
	{
		write(HIW"Õâ¸öÕÊºÅ±»ÏµÍ³¾Ü¾øÁ¬Ïß¡£Çë·¢ËÍÓÊ¼şµ½Silencer@fengyun.comÑ°Çó½â¾ö¡£\n"NOR);
		destruct(user);
		destruct(ob);
		return;
	}

	// add here:
        if ( wizardp(user))
        {// add by akuma for wiz login ip check
             if( valid_wiz_login( user->query("id"),query_ip_number(user) )==0 )
	     {
                write("¸ÃÕÊºÅÊ¹ÓÃÁË²»±»ÔÊĞíµÄIPµÇÂ½£¬ÈçÓĞÒÉÎÊ£¬Çëmailto:admin@fengyun.com£¬Ğ»Ğ»¸÷Î»Î×Ê¦µÄºÏ×÷¡£\n");
                destruct(ob);
                destruct(user);
                return;
             }
        }
	// We record this data here,.. it might be overwritten by normal quit
	ob->set("last_on", time());
	ob->set("last_from", query_ip_name(user));

	// In case of new player, we save them here right aftre setup
	// compeleted.
	user->autosave();
	ob->save();

	cloth = new("/obj/armor/cloth");
	if(objectp(cloth)) {
		cloth->move(user);
		cloth->wear();
	}
	cloth = new("/obj/login_item/wineskin");
	if(objectp(cloth)) {
		cloth->move(user);
	}
	cloth = new("/obj/login_item/beefmeat");
	if(objectp(cloth)) {
		cloth->move(user);
	}
		cloth = new("/obj/login_item/player_bag1");
	if(objectp(cloth)) {
		cloth->move(user);
	}
	if(!silent )
	{
		cat(MOTD);
	id = user->query("id");
	mailfile = DATA_DIR+ "user/" + sprintf("%c",id[0]) + "/" + id + "/mail.o";
	if( file_size(mailfile) > 0 )
			info = stat(mailfile);
	if( info && (int)info[0] >=0 )
		{
			laston = (int) ob->query("last_on");
			if( laston < info[1])
				write(HIY"\nÓĞÄúµÄĞÅ£¡Çëµ½·çÔÆ³ÇæäÕ¾À´Ò»ÌË£®£®\n\n"NOR);
		}
	write( HIR+"ÉÏ´ÎÁ¬ÏßµØÖ·£º" + ob->query("last_from") + "£¨"+
			   ctime(ob->query("last_on")) + "£©\n\n" + NOR);
	write("ÇëÇÃ»Ø³µ¼ü£Û£Ò£Å£Ô£Õ£Ò£Î£İ£®£®£®£®£®");
	input_to((:read_msg:), user );
   }
}
// this is added for check wiz_ip

private int valid_wiz_login(string id,string ip)
{
    string tmp, file;
        string *wiz_ips = ({});
        string tempip;
        int i;
        int sign=0;
        tmp=sprintf("/adm/etc/wizip/%s",id);

    // read the list of the banned sites
    // Ã»ÓĞÎÄ¼şÒ²¿ÉÒÔ½øÈ¥
    if (file_size(tmp)>0)
    {

        wiz_ips = explode(read_file(tmp), "\n");

        if(sizeof(wiz_ips)==0) return 3;
        for(i=0;i<sizeof(wiz_ips);i++)
        {
		if (regexp(ip, wiz_ips[i]) && wiz_ips[i]!="")
                {
                        sign=1;
                }
        }
	return sign;
    }
        return 1;
}
private void read_msg(string str, object user) {
	string startroom;
	object room;

	if( user->is_ghost() )
		startroom = DEATH_ROOM;
	else if( !stringp(startroom = user->query("startroom")) )
	{
		startroom = NEWBIE_ROOM;
		user->set_temp("first_time_login", 1);
	}
	
	if (wizardp(user))
		startroom = "/d/wiz/hall";

	if( !catch(load_object(startroom))) {
		if (objectp(room=load_object(startroom)) && user->move(startroom))
			user->set("startroom", startroom);
		else {
			user->move(START_ROOM);
			startroom = START_ROOM;
			user->set("startroom", START_ROOM);
		}
	} else {
		user->move(START_ROOM);
		startroom = START_ROOM;
		user->set("startroom", START_ROOM);
	}
	
	tell_room(startroom, user->query("name") +
			  "Á¬Ïß½øÈëÕâ¸öÊÀ½ç¡£\n", ({user}));

	CHANNEL_D->do_sys_channel("sys",
			  sprintf("%s(%s)ÓÉ%sÁ¬Ïß½øÈë¡£", user->name(),user->query("id"),query_ip_number(user)) );
	
	UPDATE_D->check_user(user);
	if(!wizardp(user)){
		STATUS_D->compare_status(user);
	}

	if (user->query("marry"))
		if (find_player(user->query("marry"))){
			if (find_player(user->query("marry"))->query("jiebai"))
				tell_object(find_player(user->query("marry")),HIG"ÄãµÄ°Ë°İÖ®½»"+user->query("name")+"ÉÏÏßÁË¡£\n"NOR);
			else if (find_player(user->query("marry"))->query("gender") == "ÄĞĞÔ")
				tell_object(find_player(user->query("marry")),HIG"ÄãµÄÆŞ×Ó"+user->query("name")+"ÉÏÏßÁË¡£\n"NOR);
			else
				tell_object(find_player(user->query("marry")),HIG"ÄãµÄ·ò¾ı"+user->query("name")+"ÉÏÏßÁË¡£\n"NOR);
		}
		
		
	write(HIY "\nÏÖÔÚ¹²ÓĞ"+HIR+"/cmds/wiz/sameip"->tot_usr(user)+HIY+
		  "Î»Íæ¼Ò´ÓÄãµÄÕ¾µã£¨"+query_ip_number(user)+"£©Á¬Ïß¡£\n\n"+NOR);
	user->set_temp("successful_login", 1);
	return;
}

varargs void reconnect(object ob, object user, int silent)
{
	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);
	exec(user, ob);
	// retain the old encoding scheme on reconnects.
	//user->set_temp("char_encoding", ob->query_temp("char_encoding"));

	user->reconnect();
	if( !silent )
	{
		tell_room(environment(user), user->query("name") +
				  "ÖØĞÂÁ¬Ïß»Øµ½Õâ¸öÊÀ½ç¡£\n", ({user}));
	}
	CHANNEL_D->do_sys_channel(
		"sys",sprintf("%s(%s)ÓÉ%sÖØĞÂÁ¬Ïß½øÈë¡£", user->query("name"),
					  user->query("id"), query_ip_number(user)) );
	user->set_temp("reconnected",1);
	UPDATE_D->check_user(user);
}

int check_legal_id(string id)
{
	int i;

	i = strlen(id);

	if( (strlen(id) < 3) || (strlen(id) > 8 ) )
	{
		write("¶Ô²»Æğ£¬ÄãµÄÓ¢ÎÄÃû×Ö±ØĞëÊÇ 3 µ½ 8 ¸öÓ¢ÎÄ×ÖÄ¸¡£\n");
		return 0;
	}
	while(i--) if( id[i]<'a' || id[i]>'z' )
	{
		write("¶Ô²»Æğ£¬ÄãµÄÓ¢ÎÄÃû×ÖÖ»ÄÜÓÃÓ¢ÎÄ×ÖÄ¸¡£\n");
		return 0;
	}
	if( member_array(id, banned_id)!=-1 )
	{
		write("¶Ô²»Æğ£¬ÕâÖÖÓ¢ÎÄÃû×Ö»áÔì³ÉÆäËûÈËµÄÀ§ÈÅ¡£\n");
		return 0;
	}
	return 1;
}

string random_name()
{
	string *lname = ({
"ÕÔ","Ç®","Ëï","Àî","ÖÜ","Îâ","Ö£","Íõ","·ë","³Â","ñÒ","ÎÀ","½¯","Éò","º«","Ñî","Öì","ÇØ","ÓÈ","Ğí","ºÎ","ÂÀ","Ê©","ÕÅ",
"¿×","²Ü","ÑÏ","»ª","½ğ","Îº","ÌÕ","½ª","Æİ","Ğ»","×Ş","Ó÷","°Ø","Ë®","ñ¼","ÕÂ","ÔÆ","ËÕ","ÅË","¸ğ","ŞÉ","·¶","Åí","ÀÉ",
"Â³","Î¤","²ı","Âí","Ãç","·ï","»¨","·½","Éµ","ÈÎ","Ô¬","Áø","µË","±«","Ê·","ÌÆ","·Ñ","Á®","á¯","Ñ¦","À×","ºØ","Äß","ÌÀ",
"ÌÙ","Òó","ÂŞ","»ª","ºÂ","Úù","°²","³£","ÀÖ","´ô","Ê±","¸¶","Æ¤","±å","Æë","¿µ","Îé","Óà","Ôª","²·","¹Ë","Ó¯","Æ½","»Æ",
"ºÍ","ÄÂ","Ğ¤","Òü","Ò¦","ÉÛ","Õ¿","Íô","Æî","Ã«","Óí","µÒ","Ã×","±´","Ã÷","²Ø","¼Æ","·ü","³É","´÷","Ì¸","ËÎ","Ã©","ÅÓ",
"ĞÜ","¼Í","Êæ","Çü","Ïî","×£","¶­","Áº","·®","ºú","Áè","»ô","Óİ","Íò","Ö§","¿Â","êÃ","¹Ü","Â¬","Ó¢","Íò","ºò","Ë¾Âí",
"ÉÏ¹Ù","Å·Ñô","ÏÄºò","Öî¸ğ","ÎÅÈË","¶«·½","ºÕÁ¬","»Ê¸¦","Î¾³Ù","¹«Ñò","å£Ì¨","¹«ÖÎ",
"×ÚÕş","å§Ñô","´¾ÓÚ","µ¥ÓÚ","Ì«Êå","ÉêÍÀ","¹«Ëï","ÖÙËï","Ô¯Ğù","Áîºü","ÖÓÀë","ÓîÎÄ",
"³¤Ëï","Ä»Èİ","Ë¾Í½","Ê¦¿Õ","ò§¿×","¶ËÄ¾","Î×Âí","¹«Î÷","Æáµñ","ÀÖÕı","ÈÀæá","¹«Á¼",
"ÍØÖº","¼Ğ¹È","Ô×¸¸","¹ÈÁº","³ş½ú","ÑÖ·¨","ÈêÛ³","Í¿ÇÕ","¶ÎÇ§","°ÙÀï","¶«¹ù","ÄÏ¹ù",
"ºôÑÓ","¹éº£","ÑòÉà","Î¢Éú","ÔÀ","Ë§","çÃ","¿º","¿ö","ºó","ÓĞ","ÇÙ","ÁºÇğ","×óÇğ","¶«ÃÅ","Î÷ÃÅ",
	});
	return (lname[random(200)] + chinese_number(random(20)));
}

int check_legal_name(string name)
{
	int i;
	string tempname;

	i = strlen(name);

	if( (strlen(name) < 2) || (strlen(name) > 10 ) )
	{
		write("¶Ô²»Æğ£¬ÄãµÄÖĞÎÄÃû×Ö±ØĞëÊÇÒ»µ½Îå¸öÖĞÎÄ×Ö¡£\n");
		return 0;
	}
	while(i--)
	{
		if( name[i]<=' ' )
		{
			write("¶Ô²»Æğ£¬ÄãµÄÖĞÎÄÃû×Ö²»ÄÜÓÃ¿ØÖÆ×ÖÔª¡£\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) )
		{
			write("¶Ô²»Æğ£¬ÇëÄúÓÃ¡¸ÖĞÎÄ¡¹È¡Ãû×Ö¡£\n");
			return 0;
		}
	}
	// changed by akuma
	// on 2002-10-09

	foreach(tempname in banned_name)
	{
	    if(strsrch(name,tempname)!=-1)
	    {
		    write("¶Ô²»Æğ£¬ÕâÖÖÃû×Ö»áÔì³ÉÆäËûÈËµÄÀ§ÈÅ¡£\n");
		    return 0;
	    }
    	}
	return 1;
}

int check_legal_password(object ob,string pass)
{
	int i;
	int bigletter=0;
	int smlletter=0;
	int number=0;
	string id;
	i = strlen(pass);
	if( strlen(pass) <= 5)
	{
		write("¶Ô²»Æğ£¬ÄãµÄÃÜÂë±ØĞë×îÉÙÁù¸ö×Ö·û¡£\n");
		return 0;
	}
	id= ob->query("id");
	if ( strsrch(id, pass) != -1 || strsrch(pass,id) != -1)
	{
	write("¶Ô²»Æğ£¬ÄãµÄÃÜÂëºÍÄãµÄÓ¢ÎÄÃû×ÖÌ«ÏóÁË¡£\n");
		return 0;
	}

	while(i--)
	{
		if( pass[i]<='Z' && pass[i] >='A' ) bigletter++;
		if( pass[i]<='z' && pass[i] >='a' ) smlletter++;
	}
	if( bigletter == 0 || smlletter == 0 ||
	bigletter+smlletter == strlen(pass))
	{
		write("ÄúµÄÃÜÂë±ØĞè°üº¬´óĞ´" + HIR"ºÍ" + NOR"Ğ¡Ğ´Ó¢ÎÄ×ÖÄ¸"
			  + HIR"ºÍ" + NOR"ÆäËüÌØÊâ·ûºÅ£¨Êı×Ö£¬±êµã£©¡£\n");
	return 0;
	}
	return 1;
}

object find_body(string name)
{
	object ob, *body;

	if( objectp(ob = find_player(name)) )
		return ob;
	body = children(USER_OB);
	for(int i=0; i<sizeof(body); i++)
		if( clonep(body[i]) && getuid(body[i]) == name ) return body[i];

	return 0;
}

int set_wizlock(int level)
{
	if( wiz_level(this_player(1)) <= level )
		return 0;
	if( geteuid(previous_object()) != ROOT_UID )
		return 0;
	wiz_lock_level = level;
	return 1;
}

int set_attribute(object user,int tol, int fle, int agi, int dur,
				  int intt, int str, int con, int spi, int per,
				  int cor, int cps, int kar)
{
	user->set("tol",tol);
	user->set("fle",fle);
	user->set("agi",agi);
	user->set("dur",dur);
	user->set("int",intt);
	user->set("str",str);
	user->set("con",con);
	user->set("spi",spi);
	user->set("per",per);
	user->set("cor",cor);
	user->set("cps",cps);
	user->set("kar",kar);
	return 1;
}

int cphirdir(string dirstr, string newdirstr) {
	string *dir;
	int i;
	dir = get_dir(dirstr+"/");
	if(!mkdir(newdirstr)) write("FAILED\n");
	for(i=0; i<sizeof(dir); i++) {
		if(file_size(dirstr+"/"+dir[i]) == -2 )
			cphirdir(dirstr +"/"+dir[i],newdirstr+"/"+dir[i]);
		cp(dirstr+"/"+dir[i], newdirstr+"/"+dir[i]);
	}
	return 1;
}

int set_newuser_lock( int level) {
	new_user_lock = level;
	return level;
}


int set_dummy_num( int level) {
	dummy_num = level;
	return level;
}

#ifdef MAX_USERS

int set_max_users( int num) {
	max_ppl = num;
	return num;
}

int query_max_users(){
	return max_ppl;
}

#endif

void set_dummy_number(int num){
	dummy_num = num;
}

