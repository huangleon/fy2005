
inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
�Թ����·���У�һ��ʫ�����ʫԻ������Ϸ��Σ�����գ����֮����������
�죡������ɽӳ��ˮ��һ·�������ۣ�������̲������ʯջȮ������Գ�񰧺Ź�
ľ���죬���;����������̡���˰��������ֳ�����·Ϊ��������������С�
LONG
        );
        set("exits", ([ 
  "northwest" : __DIR__"hutiao",
  "northeast" : __DIR__"shudao2",
]));
        set("outdoors", "guanwai");
	set("coor/x",420);
	set("coor/y",-650);
	set("coor/z",0);
        set("objects", ([
                __DIR__"obj/tianti" : 1,
        ]));
	setup();
}

int valid_leave(object me, string dir)
{
	
	int max_sen, max_gin;
	if (dir == "northeast")
	{
        if(random(5))
		{
			max_sen = me->query("max_sen");
			max_gin = me->query("max_gin");

			if (me->query("sen") <= max_sen /5 || me->query("gin") <= max_gin /5)
			{
				  return notify_fail("������̫���ˣ���������Ϣһ�°ɡ�\n");
			}
			me->add("gin",-(max_gin*(10+random(10))/100));
			me->add("sen",-(max_sen*(10+random(10))/100));
			me->move(this_object());
			tell_object(me,"���������ѵ�ɽ��ʰ�����ϡ�\n");
			if(me->query("sen") <= max_sen/2)
			{
				tell_object(me,"�㺹�����꣬ÿһ�����Ǽ��������Բ�Ը������ҧ��ǰ�С�\n",);
			}else
			{
				tell_object(me,"������ȥ�����������ͣ������޾�������ȴ�������ѡ�\n");
			}
			return notify_fail("");
		}
	}
	return 1;
}
