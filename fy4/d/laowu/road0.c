inherit ROOM;
void create()
{
        set("short", "�ϱ����");
        set("long", @LONG
���Ƿ��Ƴǵ�һ����Ҫ��������ϴ���ɽ��ˮ��ֱ���ɻ������½ӷ��ƾ�����
��ͨ���Ϻ��ڡ��������������ò�����һ���������Ϸ��ͱ�����չ��
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"road1",
  "south" : "/d/fycycle/fynorth",
]));
        set("outdoors", "laowu");
	set("coor/x",0);
	set("coor/y",-11040);
	set("coor/z",0);
	setup();
}
