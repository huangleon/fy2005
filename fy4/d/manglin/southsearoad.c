//Created by justdoit at May 2001 
//All Rights Reserved ^_^

inherit ROOM;
void create()
{
	set("short", "�Ϻ����");
	set("long", @LONG
����ͨ���Ϻ���һ���ؾ�֮·��·���ϵ�ɳʯԽ��Խϸ��������������һ����
ζ��Խ�����ߣ���ζԽ���ԡ�Զ���������������İ����������������������ò�����
����������ǡ������ѡ�������ʱ���Կ��������Ⱥ��ˮ�ֽ���������Ŀ�ĵض�
�����ߵġ������ѡ���ʱ��ʱҲ���˴Ӻ������������ֱ������ĺ��ǵ��̣�Ȼ��
��һͷ�����˺������
LONG
	   );
	set("exits", 
	   ([ 
	     "north" : __DIR__"plainroad",
	     "south" : __DIR__"southsearoad1",
	     "west"  : __DIR__"foxhotel",
	     "east"  : __DIR__"foxdangpu",
	    ]));
	set("objects", 
	   ([ 
         AREA_BAIYUN"npc/sailor" : 3,
	    ]));

	set("outdoors", "baiyun");
	set("coor/x",60);
	set("coor/y",-230);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}
