// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
    set("short", "�ݾ���");
    set("long", @LONG
���ﶼ�ǰ븯�õ��Ӳݺ���Ҷ���ر��������ڵ׾�����һ����«�������
�����ر�խС�����׺ܿ�����������룬���Բ������ر��������
LONG
        );
    set("objects",([
        __DIR__"npc/snake":1]));
	set("coor/x",20);
	set("coor/y",-70);
	set("coor/z",-10);
    setup();

}

void init()
{
   add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        
        if( arg == "��" || arg == "up" || arg == "well")
        {
	        me = this_player();
    	    if (me->is_busy()){
        		tell_object(me, "��������æ��\n");
        		return 1;
        	}
            message_vision("$Nץ�ž��ڼ��ѵ�������ȥ��\n", me);  
          	me->start_busy(3);
        	call_out("fliping",6,me);
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
	if (!me || me->is_ghost())	return 1;
	me->move(__DIR__"wol2");
    message_vision("$N����ʪ���ܵش�ˮ��������������\n", me);
	return 1;
}
