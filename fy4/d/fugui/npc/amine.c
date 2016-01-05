#include <ansi.h>
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
		set_name("����", ({ "tian ming","tian" }) );
        set("gender", "����" );
        set("age", 14);
		set("title","����ɽׯ "CYN"С��ͯ"NOR);
		set("nickname","���찢�������ҹ�����");
        set("long","\n");
		set("combat_exp", 50000);
        set("attitude", "friendly");
		
		set_skill("unarmed", 60);
        set_skill("birdiestrike", 50);

		set("inquiry",([
	       	"����": 	"���������Ҽ��ǿ��Ӱ����밡��\n",
	       	"����": 	"���ϴ�Ĺ���ɳ��ˣ��ҵĹ�������á�\n",
    	]) );

		map_skill("unarmed","birdiestrike");
        set("vendor_goods", ([
                __DIR__"obj/candy":200+random(200),
        ]) );
        setup();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
        add_action("do_vendor_list", "list");
		add_action("do_listskill","skills");
}

int do_listskill(string arg)
{
	object me = this_player();
	if (!arg || present(arg,environment()) != this_object())
		return 0;
	if (query("vendor_goods") 
		&& mapp(query("vendor_goods")) 
		&& sizeof(keys(query("vendor_goods"))))
	{
		message_vision("����ҡ��ҡͷ���Ǻ�«��û�������أ��һؼ�Ҫ�����̵ġ�\n\n",me);
		return 1;
	}
	write("����Ŀǰ��ѧ�����ּ��ܣ�\n\n������ȭ (birdiestrike)                    - "HIB"��������"NOR"  50/    0\n  �˻���֮�� (unarmed)                   - "HIB"������"NOR"  60/    0\n\n");
	return 1;
}



int recognize_apprentice(object ob)
{
	if (query("vendor_goods") 
		&& mapp(query("vendor_goods"))  
		&& sizeof(keys(query("vendor_goods"))))
	{
		message_vision("����ҡ��ҡͷ���Ǻ�«��û�������أ��һؼ�Ҫ�����̵ġ�\n\n",ob);
		return 0;
	}
    return 1;
}


void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(6) ) 
        {
            case 0:
                    say( "�������˱��죬ίί������˵��ʲô����ɽׯ���ö����죬�����·���û�ô���\n");
                    break;
            case 1:
                    say( "����̾�˿���˵����֪���Ҿ͹��ҵİ������˭֪������ɽׯ����������ȴ�ǰ���ɡ�\n");
                    break;
			case 2:
					say ( "��������Ŀ�����˵�������Ҳ�����\n");
                   break;
			case 3:
					say ( "����������˸��󹪣���λ��"
                            + RANK_D->query_respect(ob)
                            + "�����������ң��������Ǻ�«�ɡ�\n");
                   break;
			case 4:
					say ( "�������˿����ŵ�С���ӣ�̾������������ô���Ǻ�«������\n");
                   break;
			case 5:
					say ( "��������һ��С������Թ��˵��������������һ����û����ȥ���ؼ���Ҫ���������ˣ�����\n");
                   break;
        }
		if (!random(40))
			say("����ҧ��ҧ��������˵��ֻҪ��ֻҪ������ҵ��Ǻ�«���ң��ң��ҾͰ��ҵĹ��򶼽̸��㡣\n");
}

				
