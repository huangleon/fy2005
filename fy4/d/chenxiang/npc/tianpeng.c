// (C)1998-2000 Tie Yu
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
int tell_him();
void create()
{
	set_name("������", ({ "tianpeng lang","tianpeng" }) );
	set("gender", "����" );
	set("long","����˫�۴���ͭ�壬��˫�������Զ��һ�������ˣ���ͷ����������ֺ�����������\n");
	set("age", 45);
	set("combat_exp", 50000);
	set("attitude", "friendly");
    set("inquiry", ([
           "����" : (: tell_him :),
           "lawan" : (: tell_him:),
    		"��ʯ��" : 	"��ʯ��������������ģ��������ϵ����Ĵ���ˡ�\n",
        	"wang" :	"��ʯ��������������ģ��������ϵ����Ĵ���ˡ�\n",
        	"�����":	"��������һ�������˶��ݣ����ԲŻ���졣\n",
        	"����":		"��������һ�������˶��ݣ����ԲŻ���졣\n",
    
    ]));
    
    
            
        		
        set("vendor_goods", ([
                __DIR__"obj/yu1":8,
                __DIR__"obj/yu2":8,
                __DIR__"obj/gu":10,
                __DIR__"obj/mi":8,
        ]) );


	setup();
	carry_object("/obj/armor/cloth")->wear();
}
void init()
{
        ::init();
        add_action("do_vendor_list", "list");

}
int tell_him()
{
    	object me,obj;
		int n;
    	me =this_player();

    	if (REWARD_D->riddle_check(me,"���ȵ��")!= 9)	return 0;
        		
    	if( !me->query_temp("marks/ami"))    
    	{
        	if(me->query_temp("marks/asked_yaofang") <  5)       {
           		tell_object(me,"�����ɵ����ޣ�������Ҫ���裮������֪����֪������������ɱ��֮����\n");
           		tell_object(me,"�����ɵ������Ǵ������������������һ���žͱ��˴�ɱ���ˣ�");
            	tell_object(me,HIR"��һ���⣬��һ���⣡\n"NOR);
            	me->add_temp("marks/asked_yaofang",1);
            	return 1;
        	}
        	else if(me->query_temp("apply/jade_pro"))        {
//            	me->set_temp("marks/ami",1);
            	obj = new(__DIR__"obj/lawan");
            	obj->set("real_lawan_id",me->query("id")); 
            	tell_object(me,CYN"�����ɵ���������Ȼ�㲻����������\n\n"NOR);
            	tell_object(me,YEL"������ת����ȥ����֪���������������裮���� \n\n"NOR);
            	tell_object(me,RED"����������Ҫ����������һ˲�䣬���һ����һ��Ѫ�����ľ��������������
������ͻȻ��Ӳ��������������˵��ϡ�\n"NOR);
            	obj->move(environment(this_object()));
            	tell_object(me,WHT"\n�������㲱���ϣ�������һ�����������ã��ҿ��������ף���\n"NOR);
            	me->delete_temp("marks/asked_yaofang");
            	this_object()->die();
            	return 1;
        	}
        	else       {
            	tell_object(me,CYN"�����ɵ���������Ȼ�㲻���������� \n\n"NOR);
            	tell_object(me,YEL"������ת����ȥ����֪���������������裮���� \n"NOR);
            	tell_object(me,RED"����������Ҫ����������һ˲�䣬��ͻȻ�е��������������ʹ������\n"NOR);
            	message_vision(HIR"���һ����һ��Ѫ��$N�ľ��������������\n"NOR,me);
            	me->set_temp("last_damage_from","�ڳ����������̿ʹ�ɱ��\n");
            	me->delete_temp("marks/asked_yaofang");
            	me->die();
            	return 1;
        	}
        	return 1; 
    }
    message_vision("$N˵�������裿ʲô���裿û��˵������\n",this_object());
    return 1;
}

void reset()
{
        set("vendor_goods", ([
                __DIR__"obj/yu1":8,
                __DIR__"obj/yu2":8,
                __DIR__"obj/gu":10,
                __DIR__"obj/mi":8,
        ]) );
}
