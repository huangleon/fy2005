inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "���־�ͷ");
        set("long", @LONG
С��ķ����ܿ���ڴ˽�Ȼ��ֹ����ǰ�����ǲ�ԭ���ޱ��޼ʡ���ʱ�м����
��۹�����ʿ�����£�����һ�����к�����ǹ�����Ǵ����ڷ����������졣һ��
�����۵ĺ���󳵣���ͣ�ڽ����У������羵������б����һ���������죺
�������á�������һ���������ͣ�һ�������ѩ��
LONG
        );
        set("exits", ([ 
		"north": __DIR__"grassland1",
		"south": __DIR__"nstreet3",
	]));
        set("objects", ([
        	__DIR__"npc/yunzaitian": 1,
//        	__DIR__"obj/mache":	1,
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-10);
        set("coor/y",40);
        set("coor/z",0);
	set("map","zbwest");
	setup();

}

void init(){
//	add_action("do_enter","enter");		
}


int do_enter(string arg){
	object me,ob,cart,chefu;
	
	me=this_player();
	ob=this_object();	
	
	if (!arg || (arg!="mache" && arg!="��")) {
		tell_object(me,"��Ҫ�������\n");
		return 1;
	}
	
	if (query("mark/rented")) {
		tell_object(me,"��������տ��ߣ���һ����ɡ�\n");
		return 1;
	}
		
	if (!REWARD_D->check_m_success(me,"����߳�")){
		message_vision("\n������$N����һ��˵�����������õ�ӭ������������ʹ���������\n",me);
		message_vision("$N�����ϱ�����������\n",me);
		return 1;
	}
	
	cart=new(__DIR__"npc/obj/carriage");
    cart->move(this_object());
	    	
    chefu=new(__DIR__"npc/chefu");
    chefu->move(ob);
    chefu->get_quest(AREA_BIANCHENG"carriageway");
    chefu->set_carriage(cart);
	message_vision(WHT"һ����µ��������һ�������ʻ�˹�����\n"NOR,chefu);

	set("mark/rented",1);
	set("long", @LONG
С��ķ����ܿ���ڴ˽�Ȼ��ֹ����ǰ�����ǻ�ԭ���ޱ��޼ʡ���ʱ�м����
��۹�����ʿ�����£�����һ�����к�����ǹ�����Ǵ����ڷ����������졣һ��
���������Ĵ��ͣ�ȴ��һ�������ѩ��
LONG
        );
	message_vision("$N����������߽�����󳵡�\n\n",me);
	me->move(cart);
	chefu->go_now();
	call_out("check_status",30,chefu);
	return 1;
}


int check_status(object ob)
{
	if (!ob)	{
		set("mark/rented",0);
	        set("long", @LONG
С��ķ����ܿ���ڴ˽�Ȼ��ֹ����ǰ�����ǻ�ԭ���ޱ��޼ʡ���ʱ�м����
��۹�����ʿ�����£�����һ�����к�����ǹ�����Ǵ����ڷ����������졣һ��
�����۵ĺ���󳵣���ͣ�ڽ����У������羵������б����һ���������죺
���ض������á���һ�����������ͣ�ȴ��һ�������ѩ��
LONG
        	);
	}else	{
		call_out("check_status",30,ob);
	}
}

	