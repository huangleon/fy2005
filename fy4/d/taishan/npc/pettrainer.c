// Tie@fy
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("ɳ����", ({ "shaluomen" }) );
        set("gender", "����" );
        set("age", 62);
        set("long","ɳ�����������ã����Թ�Ƨ��ר���붯��Ϊ�飬�ó�ѱ�ޣ���������\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :)
        }) );
        setup();
        carry_object("/obj/armor/cloth")->wear();

}

void init()
{	
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_train", "train");

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "ɳ����˵������λ" + RANK_D->query_respect(ob)
                                + "����������ô�ߣ�\n");
                        break;
                case 1:
                        say( "ɳ����̾������λ" + RANK_D->query_respect(ob)
                                + "���Ұ���ѱ�ޣ���������������Ļ�����ָ��һ���һؼҵ�·�ɡ�\n");
                        break;
        }
}

int do_train(string arg)
{
	object me,pet,gold;
	int cost;
        me = this_player();
        if(me->is_busy())
        	return notify_fail("����һ��������û����ɡ�\n");
	if(!arg) 
		return notify_fail("ɳ���ŵ�������Ҫѱʲôѽ����\n");
	pet = present(arg,environment());
	if(!objectp(pet)) return notify_fail("ɳ���ŵ�������Ҫѱʲôѽ����\n");
	if(pet->query("possessed") != me )
	return notify_fail("ɳ���ŵ������Ǻ�������İɣ���\n");
//okey we identified the target, now the cost:
	
	cost = (int) pet->query("obedience");
	cost *= cost;
	gold = present("gold_money", me);
        if(!gold) return notify_fail("������û�н��ӡ�\n");
        if((int) gold->query_amount() < cost)
        	return notify_fail("������û��"+chinese_number(cost)+"�����ӡ�\n");
	if((int)me->query("score") < cost/10)
		return notify_fail("������۲���"+chinese_number(cost/10)+"�㡣\n");
	pet->add("obedience",1);
	pet->save();
	gold->add_amount(-cost);
	me->add("score",-cost/10);
	command("say ���ˣ�\n");
	return 1;
}


