inherit ROOM;
void create()
{
        set("short", "��լԺ��¥");
        set("long", @LONG
������լԺ������Ψһ���������ķ���֮һ��ԭ��ס����һ���Ѹ�����Ц����
�Ѹ��ͱ��ϻ�����ң���լԺ�ĳ��˳�Ц����ʱ��ۡ�����������ң��ȵ�һ���͹
����棬͸��������صĳ�����������С����������¥��Ҳ���԰�����Ψһ�ļ�
�����ӿ���һ���������Ҳ�ǳ�Ц���������ԭ��
LONG
        );
        set("exits", ([ 
		"down":	__DIR__"house3",
		"east":	__DIR__"house3d",
	]));
	set("objects", ([
        	__DIR__"npc/changxiao" : 1,
        ]) );

        set("item_desc", ([
	
	 ]));
	set("coor/x",-10);
	set("coor/y",-50);
	set("coor/z",10);
	set("map","taiping");
	setup();
}
