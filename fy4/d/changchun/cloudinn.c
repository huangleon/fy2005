#include <room.h>  
inherit ROOM;
void create()
{
  set("short","���ƹ�");
  set("long",@LONG
�����ǳ�����������֮������Ȼ���Ϻ����п��˵�������������Ȼ�Ǵ���������
����Ȼ���˾�����ɨ���ݽ�һ�Ŵ󴲣������̵��������롣��������С���Ϸ���һ
�Ѳ������һ�̵��Ļ���һ��С�ڡ�
LONG
  );
  	set("exits/south",__DIR__"island");
        set("objects", ([
                AREA_TIEFLAG"npc/qian1" : 1,
                AREA_TIEFLAG"npc/qian2" : 1,
       ]) ); 
	    set("resource/water",1);
	    set("liquid/name","��ˮ");
	    set("liquid/type", "water");
	    set("liquid/drunk_apply",6);
  
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
	setup();
 }
                  
