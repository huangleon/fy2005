//Created by justdoit at May 2001 
//All Rights Reserved ^_^

inherit ROOM;
void create()
{
	set("short", "�Ϻ����");
	set("long", @LONG
����ͨ���Ϻ���һ���ؾ�֮·��·���ϵ�ɳʯԽ��Խϸ��������������һ����
ζ��Խ�����ߣ���ζԽ���ԡ��������������İ�������ҲԽ��Խ������ͬʱ������
������Ÿ��������������Ķ�����һ�ҳ��⴬�ߵĴ��У���Ҫ���������Ƕ�����
�����ѯ������ֻ�ļ۸���������һ���ں��������������ͷ��
LONG
	   );
	set("exits", 
	   ([ 
	     "north" : __DIR__"southsearoad",
             "west" : "/d/shanliu/qiongjie1",
	     "south" : __DIR__"beach",
	      "east"  : __DIR__"rentingboat"
	    ]));
	set("outdoors", "baiyun");
	set("coor/x",60);
	set("coor/y",-240);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}
