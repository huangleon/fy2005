// Room: qilin.c --- by MapMaker
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");

	set("long", @LONG
����������һ�����ȡ���������������С���ϣ���ջҲûʲôǮ��������
����ҡҡ�λΣ���֨��֨�����ľͷ���ȣ�����Ϊ��Ϯһ�Ⱥ������ĵ�����һ��
��ʡ�Լ��õ��ϰ�ݺ���Ӳ�Ǽ������������еļҵ��������������˺��̺������
����Ҳ�߸߹����˴�������
LONG);

	//{{ --- by MapMaker
	set("type","indoors");
	set("exits",([
		"down":__DIR__"yuelai",
		"up":__DIR__"corridor2",
	]) );
	//}}

	set("objects", ([
        	__DIR__"npc/xiaoyezi": 1,
        ]) );
        set("indoors", "libie");
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",10);
	setup();	
}
