/* ���� -- by Silencer@fy4
	Ѳ�������������Ѳ��������
*/

inherit NPC;
#include <ansi.h> 


int info1();
int info2();
int reward;
mapping *hunter;

void create()
{
        set_name("����", ({ "xing rui","rui" }) );
        set("long","
��ͷ����ԭ���Ǿ��Ǵ��ھֵ�����ͷ���Ժ�˷��ԭ���ض�������������Ҫ
����ʮ��·���ֺ��ܣ���������������֯��һ�������п�ǰδ�еĳ�����
�ھ֡����������Ƴ��ｭ����ɱ���ң��ٸ�����ʽ΢�����ؽ�Ƹ��������
�������������񡣶������������κ����һ�ģ��������ֹе���⣬����
�����ý������ܣ����ͼ����׷�������������룬������ѯ��[33m����[32m֮�¡�
������Ѿ���Ѳ�������˳���������ѯ��[33m��ְ[32mһ�¡���Ҳ����XUNBU���鿴
��ǰ��Ѳ��������\n\n");
        set("gender","����");
	set("title", HIR"��������"NOR);
        set("age",53);
                
        set("NO_KILL",1);
        set("combat_exp", 5000000);
	set("no_arrest",1);
	
	set("inquiry", ([
		"�참":	(: info1() :),
		"Ѳ��": (: info1() :),
		"xunbu":(: info1() :),
		"����": "ѧ��֮�˵���Ч��͢���������壬�������⣬��������ѯѲ��
֮�¡�Ѳ���������Ź�ְ����ƾ��������׷ɱ�׷���\n",
		"jina": "ѧ��֮�˵���Ч��͢���������壬�������⣬��������ѯѲ��
֮�¡�Ѳ���������Ź�ְ����ƾ��������׷ɱ�׷���\n",
		"��ְ": (: info2() :),
		"ж��": (: info2() :),
		"retire": (: info2() :),
	]));
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
}
 
void init(){
	add_action("do_list","xunbu");
	::init();
}


int do_list(){
	if (this_player()->query("timer/list_hunter")+2 > time())
		return notify_fail("�����ͷ���˵���㲻�Ǹ�������ô��\n");
	this_player()->set("timer/list_hunter",time());
	PK_D->print_hunter_list();
	return 1;
}

int info1() {
	object me, ob;
	ob = this_object();
	me = this_player();
	if (PK_D->check_list(me->query("id"),"HUNTER_LIST")) {
		message_vision("����˵�����Ѿ��ǹٷ��Ѳ���ˣ�������ȥ�참��\n",ob);
		return 1;
	}
	
	if (PK_D->check_list(me->query("id"),"PK_LIST")) {
		message_vision("��������������˵��ǿ���뵱Ѳ�����������ţ�\n",ob);
		return 1;
	}
	
	message_vision(CYN"
����˵��Ѳ���������Ź�ְ����ƾ����ݿ�׷ɱ�׷�����ȡ�ͽ𣬵���
�����˾��뽭����Թ���������ϣ���Ҫ���ؿ��ǡ�\n\n"NOR,ob);
	
	if (F_LEVEL->get_level(me->query("combat_exp"))< 20) {
		message_vision(CYN"
����˵����ѧ��δ�������²��ܵ���������Σ������������ɣ�������ȼ�������\n"NOR,ob);
		return 1;
	}
	if (PK_D->count_number("HUNTER_LIST")>=50) {
		message_vision(CYN"
����˵�������Ѿ����㹻�������ˣ��������ɼΣ���һ������������ɡ�\n"NOR,ob);
		return 1;
	}
	
	tell_object(me,"���Ƿ��¶����ļ���Ѳ������answer yes/no��\n");
	me->set_temp("answer_sima",1);
	add_action("do_answer","answer");
	return 1;
}

int info2() {
	object me, ob;
	mapping player;
	me = this_player();
	ob = this_object();
	if (!(player=PK_D->check_list(me->query("id"),"HUNTER_LIST"))) {
		message_vision("����˵�����ֲ��ǹٷ��Ѳ�������¶�����û��ϵ��\n",ob);
		return 1;
	}
	if (player["join_time"]+86400*7 >time()) {
		message_vision("����˵���������������߾��ߣ���������ʲô�ط�������Ѳ������һ�ܣ�\n",ob);
		return 1;
	} else	{
		message_vision(CYN"
����˵���ţ���Ҳ��������ˣ�������������Ҳ�ã�������������ʱ
���̫�࣬���������粻ֹ��������Ե�С�ġ�\n\n"NOR,ob);
		PK_D->remove_member("HUNTER_LIST",player->query("id"));
	}
	return 1;
}


int do_answer(string arg){
	object me, hunted;
	object ob;
	mapping member =([
		"name":			"unknown",
		"id":			"unknown",
		"join_time":		0,
		"rewarded":		0,
	]);
	
	me= this_player();
	ob= this_object();
	
	if (!me->query_temp("answer_sima"))
		return 0;
	
	if (!arg || (arg!="yes" && arg!="no"))
		return notify_fail("answer yes/no \n");
	
	if (arg == "yes") {
		
		if (me->query("combat_exp")<= 500000) {
			message_vision(CYN"
����˵����ѧ��δ�������²��ܵ���������Σ������������ɡ����裱������\n"NOR,ob);
			me->delete_temp("answer_sima");
			return 1;
		}
		message_vision(YEL"$N�ᶨ�ص��˵�ͷ������������ұ�ѧ��֮����Ը������Ը�������Ρ�\n\n"NOR,me);
		me->delete_temp("answer_sima");
		member["name"]= me->query("name");
		member["id"] = me->query("id");
		member["join_time"] = time();
		member["rewarded"]= 0;
		
		if (PK_D->count_number("HUNTER_LIST")>=50) {
		message_vision(CYN"
����˵�������Ѿ����㹻�������ˣ��������ɼΣ���һ������������ɡ�\n"NOR,ob);
		return 1;
		}
		
		PK_D->add_member("HUNTER_LIST",member);
		me->save();
		ob->ccommand("spank "+me->query("id"));
		message_vision(CYN"
�����ڹ���ֽ��д��$N�����֣��ã������ڿ�ʼ��Ϳ��Լ��ø�ɱ
�����ˡ��참ʦү�Ƕ�����ϸ����������ס�������ն����Լ�Ҳ���ܻ���
����ɱ����Ҫ���������κ��ˣ��������ͬ�ţ�\n"NOR,me);		
		return 1;
	}
	
	tell_object(me,"����ԥ���Σ�ҡ��ҡͷ��\n");
	me->delete_temp("answer_sima");
	return 1;
}

