// Tie@fy3
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
ؤ�������Խ���ʮ���Ƽ��򹷰����������¡��������ڱ������´󹦣�������
�������ᴫ����Ѱ����ؤ����Ӿ�ֻ���ڴ��򴫹������ֽ̼��С�
LONG
  );
  	set("exits",([
         "west":__DIR__"gb1"
               ]));
        set("coor/x",-10);
        set("coor/y",90);
        set("coor/z",0);
	setup();
}