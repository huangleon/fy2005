// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","��ɽһʯ��");
  set("long",@LONG
һ��һ�˰��,����Ķ�Ѩ�������ϲ����˿��١���������һ�����������
����µ������ˣ�
LONG
  );
	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",5);
	set("objects", ([
		__DIR__"npc/yunzheng" : 1,
	]) );  
	
	setup();
}

void init()
{
        add_action("climbing", "climb");
}

int climbing(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
              
        if( arg == "����" || arg == "up" || arg == "vine")
        {
        	me = this_player();
        	if (me->is_busy()){
        		tell_object(me,"��������æ��\n");
        		return 1;
        	}
            
            message_vision("$Nץ��ͻ���Ŀ��٣�������˳�Źȱ�������ȥ��\n", me);
        	me->start_busy(2);
        	call_out("fliping",2,me);
        	return 1;
        }
        else
        {
                write("�㲻������"+arg+"\n");
                return 1;
        }
}


int fliping(object me)
{
	if (!me || me->is_ghost() || environment(me) != this_object())	return 1;
	
    me->move(__DIR__"pingfeng");
    message_vision("$N˳�ſ�������������\n", me);
	
    return 1;
}
