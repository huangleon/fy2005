// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ԯ��");
        set("long", @LONG
���ǻ�ɽ��ɽ������߷壬��һ·��ʯ��ᾣ���֮ǰ���ʯ���쳣
���У����Ժ������̡���˵������ǻƵ۵õ����������ڣ�Ҳ��֪���
�������������������ż����ɼ�ȷ�����ڴ��޵����ϱ���һ���壬��
���Ȼ��Լ��һé®���ƺ����˾�ס������֮�����һ��������
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"caishi",
  "north" : __DIR__"tiesuo",
]));
        set("outdoors", "huangshan");
	set("coor/x",-140);
	set("coor/y",-10);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}
