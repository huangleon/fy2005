
inherit ROOM;

void create()
{
        set("short", "���п�");
        set("long", @LONG
��������ԭ������ıؾ�֮·���������������նӶ�һ��Ҫ�����ﾭ����ʱ��
���ˣ��ͳ��˸��е����ֵļ��У����������Ķ���Щ��ɳĮ�ıر���Ʒ�����գ�ˮ
������ʳ���޾ߣ��Լ�һЩ�������飬���������ã���ʱ�����õĶ�����
LONG
        );
        set("exits", ([ 
  		"north" : __DIR__"saikou",
 		"south": __DIR__"fair2",
	]));
        set("outdoors", "quicksand");
        set("objects", ([
                
        ]) );

	set("coor/x",-1030);
	set("coor/y",-5);
	set("coor/z",0);
	setup();

}

