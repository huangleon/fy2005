// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{

	set("short", RED"��������"NOR);
    set("long", @LONG
��̤������������Ȼһ����������������������ĵط�����ط�û
��������û��������û�л��ݣ���������ʯ�����ﶼ������Ӱ���е�ֻ����
һ��ļž�����һ�����Ϣ����һ��ľ�ɫ����һ��Ĺ�Ӱ������������
�о�ֻ��һ���֣��������أ�
LONG
NOR
        );
	set("objects", ([

	]));
	set("no_fly",1);
	set("no_light",1);
	set("item_desc", ([

	"west":"ɽ���д���������ʲôҲ�ֱ治�����\n",
	"east":"ɽ���д���������ʲôҲ�ֱ治�����\n",
	"north":"ɽ���д���������ʲôҲ�ֱ治�����\n",
	"south":"ɽ���д���������ʲôҲ�ֱ治�����\n",

	]) );
	set("exits",([
  		"west" : __DIR__"bottom12",
  		"east" : __DIR__"bottom14",
	]) );

	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",-100);
	setup();
}



/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/


