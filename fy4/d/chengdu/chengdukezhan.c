// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�ɶ���ջ");
        set("long", @LONG
�ɶ���ջ�Ĺ�ģ�ϴ󡣲����оƽѡ�ʳƷ�Ҽ�������������˸��������
�����������ų����ΰ�ֽ�������������涼д�����δ����Ͷ�ޣ������翴�족��
��ҹ���ƻ��������ÿ�ԶԶ��������֪�����˴��ס��֮������һ�̣���������
��ƣ���Ͷ�Ȼ�����ˡ�
LONG
        );
	set("exits",([
  		"east" : __DIR__"nandajie1",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}