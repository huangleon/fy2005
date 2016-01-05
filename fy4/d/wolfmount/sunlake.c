#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "̫����");

	set("long", @LONG
ÿ������̫�������ʱ�򣬵�һ����������������[37m̫����[32m�ϡ������ĺ�ˮ����
�ź�������⣬����ȼ���ŵĻ��棬���е�һ�������������ξ���һ�㡣�����ʻ�
ŭ�ţ�һȺ��ͬ�ʻ�һ���������������Ů�����������ں�����Ϸ���֣�����Ʈ��
��һҶ�����ʻ���[37mС��[32m��
LONG);

	set("type","waterbody");
	set("exits",([
		"north":__DIR__"brook3",
	]) );
       set("outdoors", "wolfmount");
	set("item_desc", ([
            "boat": "һҶС�ۣ������ʻ�����[37m����[32mƮƮ������\n",
      		"С��": "һҶС�ۣ������ʻ�����[37m����[32mƮƮ������\n",
      		"lake": "��ˮ�峺��������������У�ϴ������Ľ�������(swim lake)��\n",
      		"̫����": "��ˮ�峺��������������У�ϴ������Ľ�������(swim lake)��\n",
      		"����": "�����밶�������ɣ��Ṧ�õĻ�����һԾ����(charge center)��\n",
      		"center": "�����밶�������ɣ��Ṧ�õĻ�����һԾ����(charge center)��\n",
        ]) );
	set("coor/x",-70);
	set("coor/y",-80);
	set("coor/z",0);
	setup();
}

void init(){

	add_action("do_swim", "swim");
	add_action("do_charge", "charge");

}



int do_charge(string arg)
{
        object room;
        object me;

        if(!arg || arg=="")
        {
                write("��Ҫ����������\n");
                return 1;
        }
        if( arg == "����" || arg == "center" )
        {
        	me = this_player();
        	if ( me->is_busy() )
        		return notify_fail("������æ�úܣ������ƶ���\n");
            if ( me->query_skill("dodge") >= 100 )
        	{
        		message_vision("$N����һ�ţ�������ӥ�����գ����һ��Ծ�����С��......\n", me);
        		room = find_object(__DIR__"flowerboat");
			if(!objectp(room)) room = load_object(__DIR__"flowerboat");
			me->move(room);
			message_vision("$N���ɵ�����С���ϡ�\n", me);
        		return 1;
        	}
        	else
        	{
        		message_vision(HIY"$N����ƨ�ɣ�����������׼������ķ�Ծ��\n"NOR, me);
        		message_vision(HIY"$N���ܼ�����ͻȻ����ѽ����һ������ɫ�԰׵�ͣ�ں��ߡ�\n"NOR, me);
        		me->perform_busy(3);
        		return 1;
        	}        		
        }
        else
        {
                write("�㲻����Ծ��"+arg+"\n");
                return 1;
        }
}

int do_swim(string arg)
{
        object room;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ�������Σ�\n");
                return 1;
        }
        if( arg == "̫����" || arg == "lake" )
        {
        	me = this_player();
        	if ( me->is_busy() )
        		return notify_fail("������æ�úܣ������ƶ���\n");
        	if ( random(100) > 5 )
        	{
        		message_vision(HIY"$N�����Ϸˮ�����������Ծ����С�\n"NOR, me);
        		message_vision(HIY"$NͻȻ������Щ�����Ķ�������....��$N��æ����һ���һ����λذ��ߡ�\n"NOR, me);
        		me->start_busy(2);
        		return 1;
        	}
        	else
        	{
        		message_vision(HIY"$N�߸�Ծ�𣬰����һ��ת�ۣ����������壬ֱ����С�\n"NOR, me);
        		message_vision(HIY"��ˮˮλͻȻ�½���$Nһͷ����������ʯ�ϡ�\n"NOR, me);
        		me->start_busy(3);
        		me->unconcious();
        		return 1;
        	}        		
        }
        else
        {
                write("�㲻������"+arg+"\n");
                return 1;
        }
}
