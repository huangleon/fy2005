// Tie@fy
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����", ({ "gaoren" }) );
        set("gender", "����" );
	set("title","������");
        set("age", 32);
        set("long","һ���ð�����ϵ�ʿ���Ը��ƶ�������ʱ������\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
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
                        say( "����˵������λ" + RANK_D->query_respect(ob)
                                + "����������һ�ģ�\n");
                        break;
                case 1:
                        say( "����Ц�����ⲻ���������ˣ�\n");
                        break;
        }
}

int do_train(string arg)
{
	object me,pet,gold;
	int cost;
	string which;
        me = this_player();
        if(me->is_busy())
        	return notify_fail("����һ��������û����ɡ�\n");
	if(!arg) return notify_fail("���˵�������Ҫʲôѽ����\n");
	pet = present(arg,environment());
	if(!objectp(pet)) return notify_fail("���˵�������Ҫʲôѽ����\n");
	if(pet->query("possessed") != me )
		return notify_fail("���˵������Ǻ�������İɣ���\n");
	switch (random(3)){
		case 0: which = "max_gin"; break;
		case 1: which = "max_kee"; break;
		case 2: which = "max_sen"; break;
	}	
//okey we identified the target, now the cost:
	cost = (int) pet->query(which) / 10;
	cost *= cost;
	gold = present("gold_money", me);
        if(!gold) return notify_fail("������û�н��ӡ�\n");
        if((int) gold->query_amount() < cost)
        return notify_fail("������û��"+chinese_number(cost)+"�����ӡ�\n");
	if((int)me->query("score") < cost)
	return notify_fail("������۲���"+chinese_number(cost)+"�㡣\n");
	pet->add(which,10);
	pet->save();
	gold->add_amount(-cost);
	me->add("score",-cost);
	command("say ��͵��ˣ�\n");
	return 1;
}
