inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�ݳ��");
        set("long", @LONG
����ǰ�ߣ��˼���ϡ���˵���Ȼ�����������ã�ȴ�������������������˶��
�����������������Х�ţ��ڲ�ԭ�ϱ��ܣ������㲨�ˡ���Ӧ�����׹�ʫ���
�մ�����ɽ�£������®��������Ұ����Բԣ�Ұãã���紵�ݵ���ţ��ֻ����
��û��ţ��Ҳû����ֻ��Ұ�޵��������ͷ�����
LONG
        );
        set("exits", ([ 
		"west":		__DIR__"grassland5",
	]));
        set("objects", ([
	]) );
	set("item_desc", ([
                "grass": "��������(grass)���ܣ������ƺ����Բ���(pushaside)���ǡ�\n",
                "���": "��������(grass)���ܣ������ƺ����Բ���(pushaside)���ǡ�\n"

        ]) );
	set("outdoors", "biancheng");
        set("coor/x",120);
        set("coor/y",90);
        set("coor/z",0);
	set("map","zbwest");
	setup();

}


void init()
{
        add_action("do_push", "pushaside");
}


int do_push(string arg)
{
        object me,room;
        
        if( arg == "grass" || arg == "���" || arg == "��") {
        	me = this_player();
        	if (me->query("marks/wanma/Ѱ�ض�")) {
        		tell_object(me,"������������Ļ����߶�ʮ��������������ʮ��������������ݲ�����\n");
        		tell_object(me,"��ֻ���ý��µ�����һ�ɣ���¡һ��������һ���ض���\n");
        		room=find_object(AREA_BIANCHENG"hole");
        		if (!room) room=load_object(AREA_BIANCHENG"hole");
        		message("vision",me->name()+"�������ת�˼�ת����Ȼһ���Ӿ���ʧ�ˡ�\n", environment(me),me);
			me->move(room);
        	} else 
        		message_vision("$N���ҽ���ߵ���ݲ���������ʲôҲû�з��֡�\n",me);
        	return 1;
        }   else    {
                write("��Ҫ����ʲô��\n");
 	       return 1;
        }
}