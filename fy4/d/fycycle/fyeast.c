
inherit ROOM;

void create()
{
    set("short", "���ƶ� ");
    set("long", @LONG
���Ƿ��ƳǶ���һ���м���һ���������۵Ĺٵ��������Ͷ�����չ��������Ⱥ
ɽ������������Ʋ�֪������Ŀ�������������߶���һ���޼ʵ�ׯ�ڵأ�Զ������
����б��ǵ���ʥ���䵱ɽ��
LONG
    );
    set("exits", ([ 
	"west" : AREA_FY"egate",
	"east" : AREA_EASTCOAST"palace_path1",
	"south" : __DIR__"sroad6",
	"north" :__DIR__"road6",
      ]));
    set("outdoors", "fycycle");
    set("coor/x",320);
    set("coor/y",0);
    set("coor/z",0);
    setup();
}



int valid_leave(object me, string dir)
{
    object *inv, ob;
    int i;

    if( userp(me))
    {
	if (dir == "west" && me->query_temp("annie/xiangsi_enterance") == 1)
	    me->set_temp("annie/xiangsi_enterance",2);
	else if (dir == "east" && me->query_temp("annie/xiangsi_enterance") == 5)
	    me->set_temp("annie/xiangsi_enterance",6);
	else
	    me->delete_temp("annie/xiangsi_enterance");
    }
    return 1;
}
