
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
һ��СС�Ĺ����ţ���ʯС·�����ﴩ�Ŷ��������Թ���һ��ľ�ƣ�д������
��ֹ�����ĸ����֡�������ɿ�����������һ��СС��Ժ�䣬�����������ݡ�
LONG
	);
	set("exits", ([ 
  		"east" : __DIR__"wuroad3",
  		"west" : __DIR__"wuroad1",
	]));
	set("objects", ([ 
  		__DIR__"npc/taoist3" : 1,
	]));
	set("outdoors", "wudang");
	set("coor/x",20);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

/*
int valid_leave(object me, string dir)
{
        int i;

        if( userp(me) && dir == "east" ) {
		if( (string)me->query("family/family_name")!="�䵱��" ) {
			if( (string)me->name()!="����" ) {
				me->set_temp("marks/͵", 1);
			} 
			else if( !(int)me->query_temp("marks/����") )  {
				me->set_temp("marks/͵", 1);
			}
			else {
				me->set_temp("marks/͵", 0);
			}
		}
		else {
			me->set_temp("marks/͵", 0);
		}
        }
        return 1;
}

*/