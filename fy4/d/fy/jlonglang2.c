inherit ROOM;
void create()
{
    set("short", "��������");
    set("long", @LONG
һ�˶�ߣ�ֻ�����˲��е�̴��ľ���ȣ����е����������һЩ�滨��ݡ���
�����������ȵ�һͷð������̴ľ�ذ�����ʪ�ֻ����㼸��Ҫ�������˲Ų��Ử
����
LONG
    );
    set("exits", ([
	"south" : __DIR__"jlonglang1",
	"north" : __DIR__"jlonglang3",
      ]));
    set("coor/x",-80);
    set("coor/y",-150);
    set("coor/z",0);
    set("map","fysouth");
    setup();
}
void init()
{

    add_action("do_search","search");
}

int do_search()
{

    object me,obj;
    me=this_player();
    if ((REWARD_D->riddle_check(me,"ʧ���粨")==5 ||	REWARD_D->riddle_check(me,"ʧ���粨")==4)
    	 && !query("gotit")){
       	tell_object(me,"����ʪʪ��ˮ�����������������ڷ�����һ������������\n");
		obj = new(__DIR__"obj/shangfang");
		obj->move(this_object());
		set("gotit",1);
		REWARD_D->riddle_set(me,"ʧ���粨",5);
	}else
		tell_object(me,"����ʪʪ��ˮ����������������ʲôҲû��������\n");
    return 1;
}

void reset()
{

    ::reset();
    if(query("gotit") && random(4)) set("gotit",1);
    else set("gotit",0);

} 

/*
int valid_leave(object me, string dir)
{
    if(  dir == "north" && (string)me->query("gender") != "����")
	return notify_fail("��������ԡ�ң�����ȥ��ʲô��\n");
    return 1;
}
*/