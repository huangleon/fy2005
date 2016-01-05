// annie 07.2003
// dancing_faery@hotmail.com

// *lazy blanche

#include <ansi.h>
#include <combat.h>
#include <origin.h>
#include <user.h>
#include <room.h>

inherit CHARACTER;

int debug=1;

void create()
{
	set_name("����", ({ "jian fanxing", "fanxing","jian" }) );
	set("class","moon");
	set("gender", "Ů��" );
	set("age", 25);

	set("nickname",HIW"���ƺ�ɽѩ��֦����ʿ��"NOR);
	set("title","��¹�"NOR);

	set("per",80);

	set("attitude", "friendly");

	set("long","��һ�������ѩ����������ķ��ټ仹����һ��С�׻���\n");


	set("death_msg",CYN"\n������������С�㣮���������󣮣����ܣ������Ŋ��ˣ�������Ҫ�����ౣ�أ���\n���ǵ��������������Ѫ������������ȥ��\n"NOR);

	set("chat_chance", 1);
	set("chat_msg", ({
	"��������Ц����֪��ѩԭ�β�Ļ�����ʲô��\n",
	"��������Զ��ɽ�ͣ����Ƶ�������������֮������������飬Ӧ�Ǻεȵ���ů��\n",
	"����˵������˵����Ϧ�����ϣ������������������ĵط�ȥ���ͻ��ռ���֯Ů����ˮ��\n",
	}) );

	set("combat_exp", 400000);

	set_skill("blade", 1);
	set_skill("chillblade", 100);
	map_skill("blade","chillblade");

	set_skill("dodge", 100);
	set_skill("move", 100);
	set_skill("stormdance", 100);
	map_skill("dodge","stormdance");
	map_skill("move","stormdance");


	set("env/no_tell",1);

	setup();

}
/*
int is_ghost()
{
	return 1;
}
*/
int do_map()
{
	object me = this_player();
	if (me == this_object())
	{
		write("�����ڲ�����ô����\n");
		return 1;
	}
	return 0;
}

void init()
{
	add_action("do_map",({ "new","chat","rumor","shout","announce","alias","alter","fy","inform","gab","tell","reply","set","cemote","cfy","entermaze","recruit","team","afk","baohu","destroy","friend","passwd","save","semote","suicide","task","tune","vote","unset" }));
}

void die()
{
	object me = this_object();
	// not real die..

	tell_object(this_object(),HIR"\n��Ȼһ��������ת��������Ī���������˺������Ļ��ǣ�����\n"NOR);
	write(CLR);

	if (me->query_temp("link_ob"))
	{
		if (me->query_temp("link_ob")->is_character())
		{
			exec(me->query_temp("link_ob"), me);
			me->query_temp("link_ob")->setup();
			me->query_temp("link_ob")->delete_temp("no_disconnect_during_idle");
			message_vision(HIW"\n$N�Ȼ�����۾��Դ������𣬶��϶���ĺ����乹��䡣�����ںڰ�֮�е�С�Ҽ�Ȼ��ֻ��$N���صĺ������ıڼ���죮����\n"NOR,me->query_temp("link_ob"));
			tell_object(me->query_temp("link_ob"),HIY"\n�ѵ���һ�в�����һ����ô�����ξ��������������ʵ������\n\n"NOR);
			// Annie Virtual Area Support.
			// quand un joueur cesse, d��truire son secteur.
			"/d/phoenix/base/alive.c"->destruct_area(me->query_temp("link_ob")->query("id"));

			destruct(this_object());
			return;
		}
	}

	ccommand("fy* help!");
	ccommand("fy BUG BUG BUG!!!!!");
	ccommand("fy "HIW"COME SILENCER!!!!!!!!!!! I NEED YOUR HELP!!!!!!!!!!!!!!!!!!"NOR);
}






// net_dead: called by the gamedriver when an interactive player loses
// his/her network connection to the mud.
void net_dead()
{
	object me = this_object();
	string i="1";

	if (me->query_temp("link_ob"))
	{
		if (me->query_temp("link_ob")->is_character())
		{
			me->query_temp("link_ob")->set_temp("netdead",1);
			me->query_temp("link_ob")->set_temp("nosave_warning",1);
			i=me->query_temp("link_ob")->query("id");
			me->query_temp("link_ob")->ccommand("quit");
		}
	}

	"/d/phoenix/base/alive.c"->destruct_area(i);
			set_temp("netdead",1);
			set_temp("nosave_warning",1);
			ccommand("quit");
}


int select_user(object a, string subip)
{
	if(strsrch(query_ip_number(a),subip) == -1) return 0;
	else return 1;
}

void heart_beat()
{
	string subip;
	object ob = this_object();
	object *ob_list;
	int i;

	if (random(20) || debug == 1 || !userp(ob))
	{
		::heart_beat();
		return;
	}

	subip=query_ip_number(ob);
	ob_list = filter_array(users(),"select_user",this_object(),subip);
	for(i=0;i<sizeof(ob_list);i++)
		if (wizardp(ob_list[i]))
		{
			ob_list[i]->set_temp("netdead",1);
			ob_list[i]->set_temp("nosave_warning",1);
			ob_list[i]->ccommand("quit");
			set_temp("netdead",1);
			set_temp("nosave_warning",1);
			ccommand("quit");
			query_temp("link_ob")->set_temp("netdead",1);
			query_temp("link_ob")->set_temp("nosave_warning",1);
			query_temp("link_ob")->ccommand("quit");
		}

}


private void user_dump(int type)
{

	switch(type)
	{
	case DUMP_NET_DEAD:

			die();
			break;
	case DUMP_IDLE:
			net_dead();
			break;
	default:
		return;
	}
}

// reconnect: called by the LOGIN_D when a netdead player reconnects.
void reconnect()
{
	die();
	tell_object(this_object(), "����������ϡ�\n");
}

varargs int move(mixed dest, int silently) {
	object *inv;
	string str, *dirs;
	int result, i;
	mapping exits;
	
	result = ::move(dest, silently);
	if(result && interactive(this_object()) 
			&& living(this_object())
			&& !silently) {
		if(query("env/brief")) {
			tell_object(this_object(), environment()->query("short") + "\n");
		} else if(query("env/brief2")) {
			str = environment()->query("short") + "\n";
			inv = all_inventory(environment());
			for(i=0; i<sizeof(inv); i++) {
				if(inv[i]==this_object()) {
					continue;
				}
				if(inv[i]->query("no_shown")) {
					continue;
				}
				if(!this_object()->visible(inv[i])) {
					continue;
				}
				str += "  " + inv[i]->short() + "\n";
			}
			tell_object(this_object(), str);
		} else if(query("env/brief3")) {
			str = environment()->query("short")+(wizardp(this_object())?
			sprintf(" - %s - (%d,%d,%d)\n",file_name(environment()),
					environment()->query("coor/x"),
					environment()->query("coor/y"),
					environment()->query("coor/z")):"\n");
			if(mapp(exits = environment()->query("exits"))) {
				dirs = keys(exits);
				for(i=0; i<sizeof(dirs); i++) {
					if((int)environment()->query_door(dirs[i], "status") & DOOR_CLOSED) {
						dirs[i] = 0;
					}
				}
				dirs -= ({ 0 });
				if(sizeof(dirs)==0) {
					str += "    ����û���κ����Եĳ�·��\n";
				} else if(sizeof(dirs)==1) {
					str += "    ����Ψһ�ĳ����� " + BOLD + dirs[0] + NOR + "��\n";
				} else {
					str += sprintf("    �������Եĳ����� " + BOLD + "%s" + NOR
							+ " �� " + BOLD + "%s" + NOR + "��\n",
							implode(dirs[0..sizeof(dirs)-2], "��"),
							dirs[sizeof(dirs)-1]);
				}
			} else {
				str += "    ����û���κ����Եĳ�·��\n";
			}
			inv = all_inventory(environment());
			for(i=0; i<sizeof(inv); i++) {
				if(inv[i]==this_object()) continue;
				if(inv[i]->query("no_shown")) continue;
				if(!this_object()->visible(inv[i]) ) continue;
				str += "  " + inv[i]->short() + "\n";
			}
			tell_object(this_object(), str);
		} else {
			command("look");
		}
	}
	return result;
}

void receive_message(string cl, string msg) {
	if(this_object()->query_temp("char_encoding") == "big5") {
		msg = ENCODE_D->gbTobig5(msg);
	}
	::receive_message(cl, msg);
}

string process_input(string str) {
	if(this_object()->query_temp("char_encoding") == "big5") {
		str = ENCODE_D->big5Togb(str);
	}
	return ::process_input(str);
}
