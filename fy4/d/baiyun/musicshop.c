//Sinny@fengyun 2003
//All Rights Reserved

#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", GRN"����ի"NOR);
    set("long", @LONG
����ի����ʮ�ֿ�����ȴҲ���Ե�˿���ִ٣�ի��һ���񼸣������������Σ�
��ֻ����ǰ���̵�������绩��������������һ�����ʴ�����Լϸ�£�����Сʦ��
�����͸���ի���յ��������ģ�һ�Ա��ǽ�����Ų�����֣�հ��俰£������
⢡��з˾��ӣ�������裬������ĥ��հ��俰£��������ࡣ�з˾��ӣ�����LӨ��
�������ǡ����ʫ�����磬�����к�����ʱ���˵�΢���ľ���
LONG
    );
    set("exits",
      ([
	"west" : __DIR__"skystreet2",
      ]));
    set("objects",
      ([
	__DIR__"npc/yihai" : 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",10);
    set("coor/y",-180);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
