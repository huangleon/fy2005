
inherit ROOM;

void create()
{
        set("short", "���Ҵ�Ժ");
        set("long", @LONG
ס������ľ�˵�Ǹ�����������û��ʲô�̶������⣬ֻҪ��׬Ǯ�����⣬��
������һ�ţ�������ĸ������⣬ÿ������׬��ʮ�����ӣ����ж��������ġ���˵
������Ҳ�Ǹ���⵰����ɳĮ��ת������������ͳ���ɳĮ����������ˣ����
�ĸ��̡�
LONG
        );
        set("exits", ([ 
  		"east": __DIR__"fair2",
  		"enter": __DIR__"house2",
	]));
        set("outdoors", "quicksand");
        set("objects", ([
                
        ]) );
	set("coor/x",-1032);
	set("coor/y",-10);
	set("coor/z",0);
	setup();

}

