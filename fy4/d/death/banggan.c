// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�Ӹ���");
        set("long", @LONG
�������ǹ�ƽ���ڣ����ﷸ�������壬�ù�ƽ������ȥ�ͷ����ǣ���������
���ǵ����ģ����Եز��ص����һ���������޷�����ֻ����������֮�˽����ۿΣ�
����������ֱ���л�Ϊֹ�����˱��������������±��ǳ��ڣ�ֱͨƽ�������
LONG
        );
        set("exits", ([
		"up" : __DIR__"abi",
		"down" : __DIR__"pingan",
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-180);
	set("no_fight",1);
	setup();
        
}
 
