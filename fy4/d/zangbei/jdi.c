inherit ROOM;
void create()
{
    set("short", "���");
    set("long", @LONG
�µ����ף��ŷ�������ȴ���ж��죬���ײ�����ʪ��������ൾ�ݣ���һ��һ
��һ���������оƣ��������£������б������Ϲ���һ�����ӣ���Ȼ�������ĵ���
�⣬�Ѹ������յ������õġ�
LONG
        );
    set("objects",([
        __DIR__"npc/gudongsan":1
    ]));
        set("coor/x",-460);
		set("coor/y",620);
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
          	me->start_busy(2);
        	call_out("fliping",3,me);
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
	me->move(__DIR__"banditcamp3");
    message_vision("$N��ˮ��������������\n", me);
	return 1;
}
