//mac's dongyu.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
�˴��ֳ�ӭ���ã�Ϊ�ʵ۵���̩ɽʱ��ӵĴ�����Ҳ�Ǵ�ż����ĵط�������
�����������������עĿ���˴����˳ߣ������ߣ�������ǲ��ƣ����в�������
�ģ����²�ȴ���µģ�Ϊ̩ɽ����֮һ��
LONG
  );
  	set("exits",([
         	"west":__DIR__"renan",
         	"east": __DIR__"chuihua",
               ]));
        set("objects", ([
                
        ]) );
	set("coor/x",10);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
  	replace_program(ROOM);
}
