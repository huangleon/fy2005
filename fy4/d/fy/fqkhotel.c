#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIR"����˿�ջ"NOR);
    set("long", @LONG
ǰ������һ������˫�ɵľ޻������Ź��Ŷ�ԧ��������ϵ�ż���СС�Ļ�ͭ
���塣΢���ӹ������巢������ö��Ķ�������һ�����洺���С����æµ��[37m�д�[32m
�˿ͣ�������������[37m��ֽ[32m���������ɷ����д�ż������֡��߳����ţ�ӭ����Ƕ�
��Ĵ��[37m����[32m��������һ��[37m���[32m������Ϊ���������ṩ��ˮ��
LONG);
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"huanyun4",
      ]));
    set("valid_startroom", 1);
    set("resource/water", 1);
    set("liquid/container", "ˮ��");    
    set("item_desc", ([
	"���":	"һ�ڴ�ף�ˮ����ף��������ˮ�����ߺ�«�������������ˮ��fill ������
�������������������� fill hulu
����Ϳ��Ժ��ˣ�drink hulu\n",
	"��ֽ":	"С�����ⷱæ������·���Լ�����ͼ��ʹ��mapָ�\n",
	"����": HIR" 			�� �� �� �� 
\n\n"NOR,
	"�д�": "���깩Ӧ�ϺþƲˣ���ʹ��listָ�
�����Ҫ����ʹ��buy ĳ�� from ĳ��
����Ϳ��Գ��ˣ�eat ʳ����\n",
      ]));

    set("objects", ([
	__DIR__"npc/waiter" : 1,
      ]) );

    set("coor/x",80);
    set("coor/y",-200);
    set("coor/z",0);
    set("no_dazuo",1);
    set("map","fysouth");
    setup();
    //        replace_program(NEWBIE_HELP_ROOM);
}



