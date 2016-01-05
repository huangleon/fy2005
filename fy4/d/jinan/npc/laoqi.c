// garrison.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("ӥ������", ({ "laoqi" }) );
        set("long",
 "ӥ�����߱��������Ժգ��۰�һ���İ���������Ϊ����Ͻ���ھֶ���
�ֽ�̫ƽ�����ӹ���Ѻ���Ĺ�Ʒ�����Ա���Ѻ���Σ�����һ���ܽ�׳
�ĺ��ӣ�����ȴ�ѻ���Ѫ��������һϢ��\n");

        set("attitude", "heroism");
        set("title", "ʮ�������� ��ư����");
	set("no_heal",1);
        set("cor", 26);
        set("cps", 25);
        set("kee", 5000);
        set("max_kee", 5000);
        set("eff_kee", 5);
	set("no_arrest",1);
          set("combat_exp", 1200000);

        set_skill("unarmed", 200);
        set_skill("changquan", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("move", 200);

        set_temp("apply/attack", 250);
        set_temp("apply/dodge", 220);
	set_temp("apply/parry", 220);
        set_temp("apply/damage", 50+random(100));
        set_temp("apply/armor", 100);
        set_temp("apply/move", 100);
        set("chat_chance", 1);
        set("chat_msg", ({
"ӥ������������̧��ͷ������˻�У�½С�ﰡ������ɵ�����ϴ���ⲻ��֮ԩѽ����\n",
        }) );

        setup();
    carry_object(__DIR__"obj/bloodcloth")->wear();

}


void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
		say("ӥ������������̧��ͷ������һ�ۣ��϶����������ţ����ҡ������ȣ��������壩������ �ҡ�����\n");
}

void init()
{
	::init();
	if( interactive(this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, this_player());
	}	
	add_action("do_rescue", "rescue");
}

int do_rescue(){
	object ob,money;
	if (this_player()->query("combat_exp")<1600000) {
		message_vision("ӥ������ҡ��ҡͷ�������ˣ�������Լ��������ϡ�\n",this_player());
		return notify_fail("�����㻹�ö���������п��ܽ����ɹ���\n");
		}
	if (!objectp(ob=this_player()->query_temp("weapon")))
		return notify_fail("���ñ�������û�취�ҿ�������\n");
	if (ob->query("skill_type")!="hammer")
		return notify_fail("������ֻ���ô��Ӳ����ҿ�������\n");
//	if (sizeof(environment(this_object())->query("exits"))==0)
//		return notify_fail("Ҫ���ˣ������ȿ����Űɣ�\n");				
	message_vision("$N����"+ob->query("name")+"���þ�ȫ���Ѽ����ҿ���\n",this_player());
	message_vision("$N������վ������Ҿ���ص���лл��λ"+RANK_D->query_respect(this_player())+"����֮����
������һ��������ȥ��½С���ҳ����ס����ʹ�һ��\n",this_object());
	message_vision("$N����������ʧ�ںڰ�֮�С�����\n",this_object());

	if (REWARD_D->riddle_check(this_player(),"ԡѪ����") == 2) 
		REWARD_D->riddle_done(this_player(),"ԡѪ����",50,1);

	destruct(this_object());
	return 1;
}