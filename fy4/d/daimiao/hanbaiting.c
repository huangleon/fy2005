#include <room.h>
inherit ROOM;

void create()
{
  set("short","����ͤ");
  set("long",@LONG
Ժ���Ǳ�����ַ���ֽ�����ͤ��ͤ������Ƕ����������������������������
ѧ��½�����ϳ���ʫ��л����������̩ɽ�������ڶ���̨���ϻ�����Ǭ¡��ʮ����
̩��֪�����������Ÿ�ʫ�����˰��ס��������ΪǬ¡ʫ��������ͼ�����ʫ�ȣ�
���ȱ��ȫ��
LONG
  );
  	set("exits",([
        	 "north":__DIR__"chuihua",
         	"south":  __DIR__"hanbai",
        ]));
        set("objects", ([
                
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",20);
	set("coor/y",-35);
	set("coor/z",0);
	setup();
  	
}
