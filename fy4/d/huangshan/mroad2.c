// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
ɽ·����������ƽ����Ȼ��·�治�����߿�һ���ǰٳ���Ԩ��һ��������
�ͱڡ�̽ͷ����ɽ�����絶������һ������֮����һ��СϪ�����滺������������
�������͵��±���������һ�شز�֪����ֲ���Щ�����ŵ�����С����
LONG
        );
	set("exits", ([ 
  		"eastdown" : __DIR__"qingluan",
  		"north" : __DIR__"mroad3",
	]));
    
    set("outdoors", "huangshan");
	set("coor/x",-40);
	set("coor/y",0);
	set("coor/z",20);
	setup();
}
