#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�¶���", ({ "gu du mei", "gu du" }) );
        set("nickname", "���ײ���");
        set("title", "���д��");
        set("gender", "����");
        set("age", 56);
        set("no_arrest",1);
        set("long",	"һ�����ް߰׵��ˣ�˥�ϡ��㲡�ƣ�롢���˶��־塣\n");
        setup();
        carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/sword")->wield();
}

void init()
{
        object          me;
		object          leader;
        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {       	 	
			remove_call_out("greeting");
			call_out("greeting", 1, me);
			add_action("do_agree", "agree");
        }
}

int do_agree(string arg)
{
		object		me;			
		string *route1, *route2, route, route_c;
		int *num, i, j;
		
		num = allocate(4);
		me = this_player();
		route1 = ({ "e", "n", "w", "s" });
		route2 = ({ "��","��","��", "��" });
		
        tell_object(me, "�¶��������ã����ȶ�����������󰵴����档\n");
        
        route = "";
    	route_c = "";
    	    
        for (i = 0; i<4; i++ )
        {
        	num[i] = 1+ random(6);
        	for (j=0;j< num[i] ;j++)
        	{
        		route = route + route1[i];
        	}
        	route_c = route_c + route2[i]+ chinese_number(num[i]);
        }
               
//        tell_object(me, " string is " + route + "\n");
        tell_object(me, "����һ����Ȼ��" + route_c + "���м��мǣ�\n");
        me->set_temp("marks/gudumei_walk","");
        me->set_temp("marks/gudumei_route",route);
        return 1;
}

void greeting(object ob)
{

	if( !ob || environment(ob) != environment() ) return;
	
	tell_object(ob, YEL "�¶����ĺ�����¹����ţ������˿־������¶����һ˿ϣ������Ϣ�ŵ���\n"NOR);
	tell_object(ob,YEL "�㣮������˭�����ң�û���ң����߲����ģ�(agree to help)\n"NOR);
	return;
}