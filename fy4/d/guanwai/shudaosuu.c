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
  "southwest" : __DIR__"shudao1",
  "eastup" : AREA_WOLFMOUNT"bigstage",
]));
        set("outdoors", "guanwai");

	set("coor/x",430);
	set("coor/y",-640);
	set("coor/z",0);
	setup();
}
void init()
{
        add_action("do_go","go");;
}
int do_go()
{
	object me;
	int max_sen, max_gin;
	if(random(10))
	{
		me = this_player();
		max_sen = me->query("max_sen");
		max_gin = me->query("max_gin");

		if (me->query("sen") <= max_sen /5 || me->query("gin") <= max_gin /5)
		{
              tell_object(me,"������̫���ˣ���������Ϣһ�°ɡ�\n");
			  return 1;
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
		return 1;
	}
	return 0;
}

