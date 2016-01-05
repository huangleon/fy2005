// 2009 FengYun
// Edit by hippo 2009.11

#include <ansi.h>

inherit NPC;
#include <ansi.h>
inherit F_PAWNOWNER;
inherit F_VENDOR;
void create()
{
	set_name("����", ({ "xiang ling","ling","xiangling" }) );
	set("gender", "Ů��" );
    	set("nickname", HIM"��������"NOR );
	set("age", 29);
	set("title", "�����ϰ���");
	set("long",
		"�����С������ǧ��¥��������࣬�����Ƴ������˻��ģ�
�ձ�һ�������У�ȢΪ��ʮ�˷�С���š�
�Ǹ�������HIPPO��HIPPO��ͨ�ٸ��䲼���
"+HIR"�ڴ˵�������,��Ϊ�ٸ�ͨ��Ҫ����"NOR+"\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("per",30);
	set("no_arrest",1);
	set("NO_KILL",1);
	set("richness",1000000);
	
	set_skill("dodge",200);
	set_skill("unarmed",200);
	setup();
//	carry_object(__DIR__"obj/hua_skirt")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem", "redeem");
	add_action("do_vendor_list","list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ( ob->query("gender") == "����")
{
	switch( random(5) ) {
		case 0:
message_vision("$N����������˵�������������ϣ�������λ"+RANK_D->query_respect(ob)+
"����ɶ�����������������ˣ�\n",this_object(),ob);

			break;
		case 1:
message_vision("$N��ǰ��ס$n���֣�Ц�����˵������λ"+RANK_D->query_respect(ob)+
"����������ϴ������ʱ���ߴ����ͣ�Ӣ�������ˣ���\n",this_object(),ob);
			break;
				}
}
	else
{
        switch( random(5) ) {
                case 0:
message_vision("$N��ǰ�ḧ$n�ķ�����˵������λ"+RANK_D->query_respect(ob)+
"����������£����������ˣ�\n",this_object(),ob);

                        break;
                                }


}		
}

int accept_object(object who, object ob)
{
	message_vision("$N��$n˵����л�ͣ���\n",this_object(),who);
		return 1;
}
	

