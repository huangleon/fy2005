inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "����");
        set("long", @LONG
����Լ���������˷�ŭ�ľ������������̴ܶ٣�Ȼ��һ���ֹ���ƽ������ƽ��
��������ȫ���ڰ�����Ȼ������Ǳ����Σ�գ� �㷢���ұ���һ���ţ�rightdoor����
��Ц�����ź󷢳����ģ�Ц��ͻȻ������������������������������Ķ��ջ󣬼�
ֱ�����޷��ܾ������������ƶ�����������һ���ţ�leftdoor���������ź�û��������
LONG
        );
        set("objects", ([
        __DIR__"npc/bianfu": 1,
                        ]) );
        set("item_desc", ([
                "rightdoor": "����ȻʲôҲ���������������Ѿ��ӿ���...\n",
                "leftdoor": "���ź��ұ�����һģһ����\n",
        ]) );
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",-10);
	setup();
}

void init()
{
        add_action("do_open", "open");
}

int do_open(string arg)
{
        int i;
        int damage;
        object me,room;
        if(!arg || arg=="")
        {
        	write("��Ҫ��ʲô��\n");
            return 1;
        }
        if( arg == "leftdoor" ) {
	        me = this_player();
//	�����Ppl �ӱ�Ѫ���𣬿��ܳ���һЩ��Ծ�����⣬����������call_out���ⲻ��
/*	        if (me->is_busy() || me->is_fighting()){
	        	tell_object(me,"��������æ��\n");
	        	return 1;
	        }*/
	        message_vision(HIR"$N��һ�ƿ��ţ�һ������Կ�ò����ٿ���ٶ����˳�����\n"NOR,me);
			me->receive_wound("kee",random(1000)+150);
			me->set_temp("last_damage_from","�����������������\n");
			COMBAT_D->report_status(me,1);
	        return 1;
        }
        if( arg == "rightdoor") {
            me = this_player();
/*            if (me->is_busy() || me->is_fighting()){
	        	tell_object(me,"��������æ��\n");
	        	return 1;
	        }*/
            tell_object(me,HIR"���һ�ƿ��ţ�����һ����Ͷ����Ļ������������˹�ȥ�� \n"NOR);
            message("vision",HIR""+me->name()+"��һ�ƿ��ţ�����һ����Ͷ��"+me->name()+"�Ļ�������"+me->name()+"���˹�ȥ�� \n"NOR,environment(me),me);
			room =load_object(__DIR__"room1");
			me->move(room);
            return 1;
       } 
}

