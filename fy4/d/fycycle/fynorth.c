inherit ROOM;
void create()
{
        set("short", "���ƳǱ�");
        set("long", @LONG
���Ƿ��ƳǱ���һ���м����ϱ�����ᴩ�м���������ɽ��ˮ��ֱ���ɻ�����
�Ͻӷ��ƾ�������ͨ���Ϻ��ڡ����������ò�����һ���������Ϸ��ͱ�����չ����
��������һ��С·����ͨ��ɽ��������ͨ���Į��
LONG
        );
        set("exits", ([ 
	"east" : __DIR__"road4",
  "west"  : __DIR__"road3",
  "north" : "/d/laowu/road0",
  "south" : "/d/fy/ngate",
]));
        set("outdoors", "laowu");
	set("coor/x",0);
	set("coor/y",320);
	set("coor/z",0);
        replace_program(ROOM);
        setup();
}

