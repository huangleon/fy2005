// logind.c

#define MAX_DUMMY 16 //�����������dummy
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
	"��", "��", "��", "��", "��", "��", "��",
	"����","����", "���ƣɣ�","���Ƣ�", "����",
	"����",  "����","�ɹ���","���ƣɣɣ�","���Ƣ�",
	"ϵͳ", "����", "ϵͳ����", "����2005", "���ƣ�","���ƣ�������"
	"��", "��", "������","�ƣգã�","�ƣ����",
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
		write("�Բ������ĵ�ַ���ܾ����ߡ�
��������� ������Ƶ�QQȺ 132539787 Ͷ�߲���ͨ���IP�Ρ�\n");
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
	
	if(arg == "0" || arg == "��") {
		ob->set_temp("char_encoding", "gb");
	} else if(arg == "1" || arg == "��") {
		ob->set_temp("char_encoding", "big5");
	} else {
		str = "������";
		write("    0) " + str + "(" + ENCODE_D->gbTobig5(str) + ") GB\n");
		str = "������";
		write("    1) " + str + "(" + ENCODE_D->gbTobig5(str) + ") BIG5\n");
		str = "��ѡ����ʹ�õ�����";
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
	write(sprintf(YEL"Ŀǰ����%sλ��ʿ������Ϸ�С�\n"
	"������%sλ����Ա��%sλ������ҡ���%sλ�����ߡ�\n\n" NOR,
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
				//����netbar���������ò������Ƶ�վ��
				!NETBAR_D->is_netbar(query_ip_number(ob))
				&&!NETBAR_D->is_netbar(query_ip_name(ob))
			)
			extra_num =1;
		else
			extra_num =2;
		if (log_num >= (dummy_num+1)*extra_num )
		{
			write(HIR+"��ֻ����ͬʱ��½" + chinese_number((dummy_num+1)*extra_num) + "��ID�����˳������ʺ����ԡ�\n"+NOR);
			destruct(ob);
			return;
		}
		else
		{       
			log_num= (dummy_num+1)*extra_num - log_num -1;
			write("�����ڵĵ�ַ("+YEL+query_ip_number(ob)+NOR")��������"YEL+chinese_number(log_num)+NOR"λ������ߡ�\n\n");
		}
	}
	
	write("����Ӣ�����֣�");
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
		write("����Ӣ�����֣�");
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
			write("�Բ���"+MUD_NAME+"��ʹ�����Ѿ�̫���ˣ������������\n");
			destruct(ob);
			return;
		}
	}
#endif

	if( wiz_level(arg) < wiz_lock_level && SERV != LOCAL )
	{
		write("�Բ���" + MUD_NAME +
			  "Ŀǰ����ά��֮�У����Ժ������ߡ�\n");
		destruct(ob);
		return;
	}

	if (uptime()< 300 && !wiz_level(arg) && SERV != LOCAL ) {
		write("����ϵͳ���ڳ�ʼ������������Ӻ��ٵ�½��\n");
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
				write("��Ӣ�������ѱ�ʹ�ã���������ʺŵ����룺");
				input_to((:get_passwd:), 1, ob);
			} else
			{
				write("��Ӣ�������ѱ�ʹ�ã���������ʺŵ����룺");
				input_to((:get_passwd:), 1, ob);
/*				alle="/feature/nada.c"->my_number();
				write("\n");
				write(alle[0]);
				write("\n����������У���룺");
				input_to((:get_verify_code:),1,ob,alle[1],1);  */ //  add by ldb �رշ��˵�����У�� 
			}                            
			return;                
		}
		write("�������ﴢ�浵����һЩ���⣬������ guest ����֪ͨ��ʦ����\n");
		destruct(ob);
		return;
	}
	if(new_user_lock)
	{
		write("���ڷ��Ʋ������µ�������Ժ��ٴ����µ����\n");
		destruct(ob);
		return;
	}
	usr = filter_array(children(LOGIN_OB), (: interactive :));
	i = sizeof(usr);
	while (i--)
		if (usr[i] != ob && usr[i]->query("id") == arg)
			break;
	if (i >= 0) {
		write("�������������ʹ����� ID�����������롣\n");
		write("����Ӣ�����֣�");
		input_to((:get_id:), ob);
		return;
	}
	write("ʹ�� " + (string)ob->query("id") +
		  "\n������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
	input_to( (: confirm_id :), ob);
}


private void get_verify_code(string an,object ob,int answer,int chs)
{
	int ans;
	if( sscanf(an, "%d", ans)==1 ) {
		if( ans==answer ) {
			if (chs == 1)
			{
				write("��Ӣ�������ѱ�ʹ�ã���������ʺŵ����룺");
				input_to((:get_passwd:), 1, ob);
				return;
			}
		if (chs == 2) {
	write( @TEXT
[37m
������һ���Թ���С˵Ϊ���������磬������һ�������ʣ��и���
���������ִ��������������ִ����󽫲����ٸ��ġ�

�벻Ҫʹ�ù���С˵����������һЩͨ�׵ĳƺ����������������
��Ҫʹ�þ��в�������������ԵĴʣ��緢�ִ�����������ƹ���
�鱣����������ɾ���������Ȩ����

[31m
����������������������֣���ֱ���ûس����ۣңţԣգңΣݡ�
[32m
TEXT
		);
					write("�����������֣�");
					input_to((:get_name:), ob);
				return;
			}
		}
	}
	write("У��δ��ͨ����\n");
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
		write("��������жϵ�½����\n");
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

		write("\n��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮�𣿣�(y/n)");
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
				write("������û�н�����Ƶ�Ȩ��������"+ (60-(time() - user->query("kickout_time"))/60) + "���Ӻ������ߡ�\n");
				destruct(user);
				destruct(ob);
				return;
			}
			enter_world(ob, user);
			return;
		}
		else  destruct(user);
	}
	write("�������´���������\n");
	confirm_id("y", ob);
}

private void confirm_relogin(string yn, object ob, object user)
{
	object old_link;

	if(!objectp(user)) {
		write("��һ�������е���ͬ�����Ѳ����ڣ����������ߡ�\n");
		destruct(ob);
		return;
	}

	if(yn=="") {
		write("\n��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
		input_to((:confirm_relogin:), ob, user);
		return;
	}

	if(yn[0]!='y' && yn[0]!='Y') {
		write("�ðɣ���ӭ�´�������\n");
		destruct(ob);
		return;
	} else {
		tell_object(user, "���˴ӱ�( " + query_ip_name(ob)
					+ " )����ȡ���������Ƶ����\n");
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
		write("ʹ��������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
		input_to((:confirm_id:), ob);
		return;
	}

	if( yn[0]!='y' && yn[0]!='Y' )
	{
		write("�ðɣ�������������������Ӣ�����֣�");
		input_to((:get_id:), ob);
		return;
	}
			alle="/feature/nada.c"->my_number();
			write("\n");
			write(alle[0]);
			write("\n����������У���룺");
			input_to((:get_verify_code:),1,ob,alle[1],2);       

	return;                                              
}

private void get_resp(string arg, object ob)
{
	if( arg=="" )
	{
		write("������(y)������(n)����������֣�");
		input_to((:get_resp:), ob);
		return;
	}

	if( arg[0]=='y' || arg[0]=='Y' )
	{
	//	printf("%O\n", ob);
		ob->set("name", Rname);
		write("[37m
����������������ַ����Ұ�����Сд��ĸ�����ֻ���
	[1;31m���趨�������룺[0;32m\n");
		input_to((:new_password:), 1, ob);
		return;
	}
	else if( arg[0]=='n' || arg[0]=='N')
	{
		Rname = random_name();
		write("������(y)������(n)����������֣�");
		printf( HIY" -- %s ��"NOR, Rname);
		input_to((:get_resp:), ob);
		return;
	}
	else
	{
		write("�Բ�����ֻ��ѡ������(y)������(n)�� ");
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
		write("������Ҫ������������������֣���\n");
		write("������(y)������(n)����������֣�");
		printf( HIY" -- %s ��"NOR, Rname);
		input_to((:get_resp:), ob);
	}
	else
	{
		if(ob->query_temp("char_encoding") == "big5") {
			arg = ENCODE_D->big5Togb(arg);
		}
		if( !check_legal_name(arg) )
		{
			write("�����������֣�");
			input_to((:get_name:), ob);
			return;
		}

		printf("%O\n", ob);
		ob->set("name", arg);
		write("���趨�������룺");
		input_to((:new_password:), 1, ob);
	}
}

private void new_password(string pass, object ob)
{
	write("\n");
	if( !check_legal_password(ob,pass))
	{
		input_to((:new_password:), 1, ob);
		write("���趨�������룺");
		return;
	}
	ob->set("password", crypt(pass,0) );
	write("��������һ���������룬��ȷ����û�Ǵ�");
	input_to((:confirm_password:), 1, ob);
}

private void confirm_password(string pass, object ob)
{
	string old_pass;
	write("\n");
	old_pass = ob->query("password");
	if( crypt(pass, old_pass)!=old_pass ) {
		write("��������������벢��һ�����������趨һ�����룺");
		input_to((:new_password:), 1, ob);
		return;
	}
	write("������Ժ���ʧ�����������룬ֻ��ƾ�˵����ʼ���ַ���ָܻ���\n");
	write("���ĵ����ʼ���ַ��");
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

	write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
	input_to((:get_gender:), ob, user);
}

private void get_gender(string gender, object ob, object user)
{
	if( gender=="" )
	{
		write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
		input_to((:get_gender:), ob, user);
		return;
	}

	if( gender[0]=='m' || gender[0]=='M' )
		user->set("gender", "����");
	else if( gender[0]=='f' || gender[0]=='F' )
		user->set("gender", "Ů��" );
	else
	{
		write("�Բ�����ֻ��ѡ������(m)��Ů��(f)�Ľ�ɫ��");
		input_to((:get_gender:), ob, user);
		return;
	}
	
	// New login bypass race
	
	user->set("national", "����");
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
		write("���ڿ������������޸�ʹ��������ĳ�ʽ���޷����и��ơ�\n");
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
	user->set("title", "��ͨ����");
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

	write(CLR + "ĿǰȨ�ޣ�" + wizhood(user) + "\n");
	user->setup();

	// Add by annie. Block bugged account.
	if(ob->query("blocked") && !wizardp(user))
	{
		write(HIW"����ʺű�ϵͳ�ܾ����ߡ��뷢���ʼ���Silencer@fengyun.comѰ������\n"NOR);
		destruct(user);
		destruct(ob);
		return;
	}

	// add here:
        if ( wizardp(user))
        {// add by akuma for wiz login ip check
             if( valid_wiz_login( user->query("id"),query_ip_number(user) )==0 )
	     {
                write("���ʺ�ʹ���˲��������IP��½���������ʣ���mailto:admin@fengyun.com��лл��λ��ʦ�ĺ�����\n");
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
				write(HIY"\n�������ţ��뵽���Ƴ���վ��һ�ˣ���\n\n"NOR);
		}
	write( HIR+"�ϴ����ߵ�ַ��" + ob->query("last_from") + "��"+
			   ctime(ob->query("last_on")) + "��\n\n" + NOR);
	write("���ûس����ۣңţԣգңΣݣ���������");
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
    // û���ļ�Ҳ���Խ�ȥ
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
			  "���߽���������硣\n", ({user}));

	CHANNEL_D->do_sys_channel("sys",
			  sprintf("%s(%s)��%s���߽��롣", user->name(),user->query("id"),query_ip_number(user)) );
	
	UPDATE_D->check_user(user);
	if(!wizardp(user)){
		STATUS_D->compare_status(user);
	}

	if (user->query("marry"))
		if (find_player(user->query("marry"))){
			if (find_player(user->query("marry"))->query("jiebai"))
				tell_object(find_player(user->query("marry")),HIG"��İ˰�֮��"+user->query("name")+"�����ˡ�\n"NOR);
			else if (find_player(user->query("marry"))->query("gender") == "����")
				tell_object(find_player(user->query("marry")),HIG"�������"+user->query("name")+"�����ˡ�\n"NOR);
			else
				tell_object(find_player(user->query("marry")),HIG"��ķ��"+user->query("name")+"�����ˡ�\n"NOR);
		}
		
		
	write(HIY "\n���ڹ���"+HIR+"/cmds/wiz/sameip"->tot_usr(user)+HIY+
		  "λ��Ҵ����վ�㣨"+query_ip_number(user)+"�����ߡ�\n\n"+NOR);
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
				  "�������߻ص�������硣\n", ({user}));
	}
	CHANNEL_D->do_sys_channel(
		"sys",sprintf("%s(%s)��%s�������߽��롣", user->query("name"),
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
		write("�Բ������Ӣ�����ֱ����� 3 �� 8 ��Ӣ����ĸ��\n");
		return 0;
	}
	while(i--) if( id[i]<'a' || id[i]>'z' )
	{
		write("�Բ������Ӣ������ֻ����Ӣ����ĸ��\n");
		return 0;
	}
	if( member_array(id, banned_id)!=-1 )
	{
		write("�Բ�������Ӣ�����ֻ���������˵����š�\n");
		return 0;
	}
	return 1;
}

string random_name()
{
	string *lname = ({
"��","Ǯ","��","��","��","��","֣","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","ʩ","��",
"��","��","��","��","��","κ","��","��","��","л","��","��","��","ˮ","�","��","��","��","��","��","��","��","��","��",
"³","Τ","��","��","��","��","��","��","ɵ","��","Ԭ","��","��","��","ʷ","��","��","��","�","Ѧ","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʱ","��","Ƥ","��","��","��","��","��","Ԫ","��","��","ӯ","ƽ","��",
"��","��","Ф","��","Ҧ","��","տ","��","��","ë","��","��","��","��","��","��","��","��","��","��","̸","��","é","��",
"��","��","��","��","��","ף","��","��","��","��","��","��","��","��","֧","��","��","��","¬","Ӣ","��","��","˾��",
"�Ϲ�","ŷ��","�ĺ�","���","����","����","����","�ʸ�","ξ��","����","�̨","����",
"����","���","����","����","̫��","����","����","����","ԯ��","���","����","����",
"����","Ļ��","˾ͽ","ʦ��","��","��ľ","����","����","���","����","����","����",
"��ֺ","�й�","�׸�","����","����","�ַ�","��۳","Ϳ��","��ǧ","����","����","�Ϲ�",
"����","�麣","����","΢��","��","˧","��","��","��","��","��","��","����","����","����","����",
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
		write("�Բ�������������ֱ�����һ����������֡�\n");
		return 0;
	}
	while(i--)
	{
		if( name[i]<=' ' )
		{
			write("�Բ�������������ֲ����ÿ�����Ԫ��\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) )
		{
			write("�Բ��������á����ġ�ȡ���֡�\n");
			return 0;
		}
	}
	// changed by akuma
	// on 2002-10-09

	foreach(tempname in banned_name)
	{
	    if(strsrch(name,tempname)!=-1)
	    {
		    write("�Բ����������ֻ���������˵����š�\n");
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
		write("�Բ����������������������ַ���\n");
		return 0;
	}
	id= ob->query("id");
	if ( strsrch(id, pass) != -1 || strsrch(pass,id) != -1)
	{
	write("�Բ��������������Ӣ������̫���ˡ�\n");
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
		write("����������������д" + HIR"��" + NOR"СдӢ����ĸ"
			  + HIR"��" + NOR"����������ţ����֣���㣩��\n");
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

