// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���ִ�Ӱ��ֱ�����������ı���Ϊ��ɮ�������������ĵ�����ɮ��Ԫ׫��
��[33mϢ����ʦ����֮��[32m�����漪������Ȼ�鵤����������ɮϢ�ֵ���ƽ��ѧ��֮
�˵���Ч��Ϣ����Ϊ�����ܳ�һ����ʦ��
LONG
        );
        set("exits", ([ 
  		"west" : __DIR__"bei1",
  		"southeast" : __DIR__"yingbi",
	]));
        set("objects", ([
               BOOKS"skill/xiaocheng_50" : 1,
       	]) );
        set("outdoors", "shaolin");
	set("coor/x",-10);
	set("coor/y",-80);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
