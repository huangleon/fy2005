// Tie@fy
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("��һ��", ({ "yimo" }) );
        set("gender", "����" );
	set("title","һ��ȫ");
        set("age", 52);
        set("long","һ����������ͷ���������ģ�һ���������ˣ�����\n");
        set("combat_exp", 5000);
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :)
        }) );
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
                        say( "��һ��˵������λ" + RANK_D->query_respect(ob)
                                + "����������һ����\n");
                        break;
                case 1:
                        say( "��һ��Ц������λ" + RANK_D->query_respect(ob)
                                + "��������������һ�ѣ�\n");

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
	if(!arg) return notify_fail("��һ����������Ҫʲôѽ����\n");
	pet = present(arg,environment());
	if(!objectp(pet)) return notify_fail("��һ����������Ҫʲôѽ����\n");
	if(pet->query("possessed") != me )
	return notify_fail("��һ���������Ǻ�������İɣ���\n");
	switch (random(9)){
		case 0: which = "int"; break;
		case 1: which = "con"; break;
		case 2: which = "per"; break;
	        case 3: which = "cor"; break;
	        case 4: which = "str"; break;
	        case 5: which = "fle"; break;
	        case 6: which = "agi"; break;
	        case 7: which = "tol"; break;
	        case 8: which = "dur"; break;
			}	
//okey we identified the target, now the cost:
	cost = (int) pet->query(which) ;
	cost *= cost;
	gold = present("gold_money", me);
        if(!gold) return notify_fail("������û�н��ӡ�\n");
        if((int) gold->query_amount() < cost)
        return notify_fail("������û��"+chinese_number(cost)+"�����ӡ�\n");
	if((int)me->query("score") < cost)
	return notify_fail("������۲���"+chinese_number(cost)+"�㡣\n");
	pet->add(which,1);
	pet->save();
	gold->add_amount(-cost);
	me->add("score",-cost);
	command("say ���𣡣��´��ٶ������£�\n");
	return 1;
}
