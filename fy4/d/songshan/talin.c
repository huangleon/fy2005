
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���������£�����ɽ������֮�أ�ռ������ƽ���ף�����������ʱǧ�������
���ɣ���ɮ������ڴˣ����СС���ٶ�ʮ����שʯĹ��������������ǰ�ķ�ѧ
��λ�������ȵȴ�С��һ�����²�һ�������š�Ĺ�����͸��죬���о��Ŵ�שʯ��
������������ı��⣬��Ϊ�����ı������ú��о͹�������ɮ�ľ�������
LONG
        );
        set("exits", ([ 
  			"east" : __DIR__"houmen",
  			"northeast" : __DIR__"huishan",
  			"northwest" : __DIR__"damo",
  			"south" : __DIR__"erzu",
		]));
        set("outdoors", "songshan");
        set("objects", ([
                __DIR__"obj/ta1" : 1,
                __DIR__"npc/lama3" : 1,
       ]) );
        
        
		set("coor/x",65);
		set("coor/y",25);
		set("coor/z",0);
		setup();

}

void init()
{
        add_action("climbing", "climb");
}

int climbing(string arg)
{
        object obj, room;
        object me;
        if(!arg || arg=="")
        {
                return 0;
        }
        if( arg == "tower" || arg == "��" || arg == "�͹���" || arg == "up")
        {
	        me = this_player();
        	if (me->is_busy() || me->query_temp("climb/jiugong"))
        		return notify_fail("��������æ��\n");
        	
        	if (REWARD_D->riddle_check( me, "��������") != 2)
        		return notify_fail("����������֮�أ�û�¶���������\n");
        	
        	if (!room= find_object(__DIR__"talin_top"));
        		room = load_object(__DIR__"talin_top");
        	
        	if (room->usr_in())
        		return notify_fail("�����ƺ�վ������ˣ�û��������֮�ء�\n");

			room->reset();
			        	        			
        	message_vision("$N����һԾ�����ȵ����ھ͹�������\n", me);
        	me ->move(room);
            return 1;
        }
        else
        {
                write("�㲻������"+arg+"\n");
                return 1;
        }
}
