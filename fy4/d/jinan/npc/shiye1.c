/* ���� -- by Silencer@fy4
	1���г�����������
	2�������참������
	3���ܻ����ӷ��ˡ�
*/


inherit NPC;
inherit F_VENDOR;

#include <ansi.h> 

int info1();
int info2();
int reward;

void create()
{
        set_name("�참ʦү", ({"shi ye","shiye"}));
        set("long","
���еİ��ӣ������ʦү�ܡ������CHECK�鿴��ǰ��ͨ��Ҫ��������
Ŀǰ��ʦү��ʱ���ܳ������顣\n");
        set("gender","����");
	set("title", HIC"������˽"NOR);
                
        set("NO_KILL",1);
        set("combat_exp", 5000000);
	set("no_arrest",1);
	
	set("inquiry", ([
		"�참":	"���÷��˵��£����϶�ͷ�ƹܡ�\n",
		"����": "���÷��˵��£����϶�ͷ�ƹܡ�\n",
		"Ѳ��": "���÷��˵��£����϶�ͷ�ƹܡ�\n",
		"����": "��ְ֮�£����϶�ͷ�ƹܡ�\n",
		"жְ": "��ְ֮�£����϶�ͷ�ƹܡ�\n",
		"ͨ��": "����ͨ��ʲô�ˣ�������ô��\n",
		"�ӷ�": "��֪��˭���ӷ�����һ�¸�ʾ��֪���ˡ�\n",
		"����":	"������пհ׵ģ�����һ�����ϣ������������˵����ָ��ҡ�\n"
	]));
        set("vendor_goods", ([
                __DIR__"obj/gongwen" : 100,
        ]) );	
	
        setup();
        carry_object("/obj/armor/cloth")->wear();
}
 
void init(){
	add_action("do_vendor_list","list");
	add_action("do_check","fugitive");
	::init();
}


int do_check(){
	if (this_player()->query("timer/list_pk")+2 > time())
		return notify_fail("�참ʦү���ͷ���˵���㲻�Ǹ�������ô��\n");
	this_player()->set("timer/list_pk",time());
	PK_D->print_pk_list();
	return 1;
}


int accept_object(object me, object item){

	string hunted_name;
	object hunted, ob;
	mapping hunted_old;
	
	ob = this_object();
	
	if (!item->query("official_seal"))
		return notify_fail("�참ʦү�������ϵ�˵������ֻ�չ��ģ���̸˽�¡�\n");
		
	if (!hunted_name = item->query("hunted_name"))
		return notify_fail("�참ʦү�ɻ��˵��һֽ���ģ����Һ��ã�\n");
		
	hunted = find_living(hunted_name);
	if (!hunted || (hunted && hunted->query("wiz_invis")))
		return notify_fail("�참ʦү����Ƭ�̣����˶�����˵���Ҵ���û��˵������ˡ�\n");
	
	if (!userp(hunted))
		return notify_fail("�참ʦүҡҡͷ˵����������֮���˽�˶�Թ������������\n");
		
	if (hunted == me)
		return notify_fail("�참ʦү˵������Ͷ������ȥ���ϴ��Σ����������ɱ��ǡ�\n");
		
	
	if (!hunted->query("NO_PK")) {
	if (PK_D->check_list(hunted->query("id"),"HUNTER_LIST"))
		return notify_fail("�참ʦү��ɫ����"+hunted->name()+"Ϊ������������ô�����Ǵ����أ�\n");
	else if (PK_D->check_list(hunted->query("id"),"PK_LIST")) 
		return notify_fail("�참ʦү˵�������Ѿ��ڱ����ļ����������ˣ�����check�鿴��\n");
	}	
	
	if (PK_D->check_list(hunted->query("id"),"PK_LIST")) {
		message_vision(CYN"�참ʦү˵�������Ѿ��ڱ����ļ����������ˣ�����check�鿴��\n",ob);
		return 1;
	}
	
	if (PK_D->count_number("PK_LIST")>=50) {
		message_vision(CYN"
�참ʦү˵�������ӷ�̫�࣬�������ۣ��������°���\n",ob);
		return 1;
	}
	
	message_vision(CYN"
�참ʦү����һ����������û��˵���������ʲô�Ӽ�����������
�참ʦү�������ﱳ�������˼�Ȧ���ߵ��ſڰ��Ź��ϣ�������ǰ�����̲�Ū�˼��£�
������$n΢΢һЦ������������ʦүҲ��������´��һ�£�����������\n"NOR,ob,me);
	reward = 10; // Default cost
	if( mapp(hunted_old = PK_D->check_list(hunted->query("id"),"PK_OLD_LIST")) ) {
		if( hunted_old["start_time"] + 388800 > time() ) {
			reward = hunted_old["reward"]*2;
			if( reward > 20 ) {
				// ��������������
				reward = 30;
			}
		}
	}
	tell_object(me, CYN"\nʦү������İ�ֽ��д�˼������֣�
��б��һ�������ģ���"+reward+"�����ӣ���answer yes/no��\n"NOR);
	me->set_temp("answer_shiye1",1);
	me->set_temp("hunted_cand",hunted);
	add_action("do_answer","answer");
	return 1;
}

int do_answer(string arg){
	object me, hunted;
	object ob;
	mapping member =([
		"hunted":		"unknown",
		"name":			"unknown",
		"start_time":		0,
		"reward":		0,
		"initializer":		"none",
	]);
	
	me= this_player();
	ob= this_object();
	
	if (!me->query_temp("answer_shiye1"))
		return 0;
	
	if (!arg || (arg!="yes" && arg!="no"))
		return notify_fail("answer yes/no \n");
	
	if (arg == "yes") {
		if (me->query("deposit")< reward*10000) {
			tell_object(me,CYN"�참ʦү��Цһ���������û��������ɣ�\n"NOR);
			me->delete_temp("hunted_cand");
			me->delete_temp("answer_shiye1");
			return 1;
		}
		message("vision",CYN""+me->name()+"�չ�ȥ���ڰ참ʦү�Ķ�������ǰ�ص����˼��䡣\n"NOR,
			environment(ob),me);
		tell_object(me,"�᲻�ú����ײ����ǣ���ҧҧ�������ͷ��Ӧ��ʦү��\n");
		if (!objectp(hunted = me->query_temp("hunted_cand"))) {
			message_vision(CYN"�참ʦүһ̯��˵�����ˣ������Ѿ�ʧ���ˡ�\n"NOR,me);
			me->delete_temp("hunted_cand");
			me->delete_temp("answer_shiye1");
			return 1;
		}
		if (PK_D->check_pk_list(hunted->query("id"),"PK_LIST")) {
			message_vision(CYN"�참ʦү˵�������Ѿ��ڱ����ļ����������ˣ�����check�鿴��\n",ob);
			me->delete_temp("hunted_cand");
			me->delete_temp("answer_shiye1");
			return 1;
		}
		me->add("deposit",-reward*10000);
		message_vision(CYN"�참ʦү����һЦ��ž��һ���ڹ���ֽ�ϸ��Ϲٸ���ӡ��\n"NOR, ob);
		me->delete_temp("hunted_cand");
		me->delete_temp("answer_shiye1");
		member["hunted"]= hunted->query("id");
		member["name"]= hunted->query("name");
		member["start_time"]= time();
		member["reward"]= reward;
		member["initializer"] = me->query("id");
		PK_D->add_member("PK_LIST",member);
		me->save();
		return 1;
	}
	
	tell_object(me,"�������룬ҡ��ҡͷ��\n");
	me->delete_temp("hunted_cand");
	me->delete_temp("answer_shiye1");
	return 1;
}


void reset()	{
	set("vendor_goods", ([
                __DIR__"obj/gongwen" : 100,
        ]) );	
}