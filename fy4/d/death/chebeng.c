// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
ǡ��ս��ʱ��������ʬ��Ҳ�Ƴ��ѣ������֣�һ���ǽ��ﷸ��֫����������
��ԯ�ϣ�Ȼ���ڳ��������ۣ�һ������ǧ��ս��������������������Ҳ��ֳ�
���Ρ��������˼����Էϳ����ã������ڵ�������һ�������̿��ң������˼䷸��
����ش󵽼��㡣����������һ�෸���ˣ��ֵ�����أ�
LONG
        );
        set("exits", ([
		"up" : __DIR__"zhuidao",
		"down" : __DIR__"hanbing",
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-90);
	set("no_fight",1);

	setup();
        replace_program(ROOM);
}
 
