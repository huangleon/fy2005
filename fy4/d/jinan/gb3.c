// Tie@fy3
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
ؤ���Ϊ���µ�һ�����ڳ�ǧ���򣬶�����֮��Ҳ�Ǹ���֮�ڣ����ԡ���
�����ϡ�����ؤ������֮����ؤ�������������к�ʧְ�����Ա������˴����
�����ϵķ��䡣
LONG
  );
  	set("exits",([
         "east":__DIR__"gb1"
               ]));
        set("coor/x",-30);
        set("coor/y",90);
        set("coor/z",0);
	setup();
}