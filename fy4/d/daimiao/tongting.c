#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
  	set("short","ͭͤ����");
  	set("long","����Ժ�Ķ������࣬����������עĿ�Ĺż�����Ϊͭͤ����Ϊ������ͭͤ��
�������ڡ���Ϊ��������ʮһ������ͤΪͭ�ʣ�ʩ���̽�����Ԫ��ͭ����ҫ
Ŀ����ׯ���ء����������Ϊ���ξ������������������ΰ�����Ͽ����������ƣ�
ɽˮ��ʯ��Ԣ��������գ����������ɽ���곤����˼��Ժ�и���"YEL"�Ű�"NOR"���á�
"
  );
  	set("exits",([
         	"north":__DIR__"houzai.c",
         	"south":__DIR__"houqing.c",
        ]));
        set("objects", ([
            	"/obj/specials/ding/ding_dm" : 1,
            	__DIR__"npc/xi" : 1,
       	]) );
       	set("item_desc", ([
        	"�Ű�":"
��԰����ǽ�£�Ҳ��һ�ùŰأ��Դ�������ϣ���ӵ��ï�ܵ�֦Ҷ������
һ�����ƶ䣬���Ա���Ϊ��������̨��������Ϊ���˾�֮һ��\n",
        	"��":"
��԰����ǽ�£�Ҳ��һ�ùŰأ��Դ�������ϣ���ӵ��ï�ܵ�֦Ҷ������
һ�����ƶ䣬���Ա���Ϊ��������̨��������Ϊ���˾�֮һ��\n",
		"tree":"
��԰����ǽ�£�Ҳ��һ�ùŰأ��Դ�������ϣ���ӵ��ï�ܵ�֦Ҷ������
һ�����ƶ䣬���Ա���Ϊ��������̨��������Ϊ���˾�֮һ��\n",
        ]) );
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
	setup();
  	
}

int valid_leave(object who, string dir) {
	object wei;
	
	if (who->query("class") == "demon")
		return 1;

	if (dir == "south") {
		if (wei = present("xi wei",this_object()))
		if (!userp(wei) && !who->query_temp("daimiao/passwd") ) {
			return notify_fail(wei->name()+"�ȵ������������answer��\n");
		if (who->query("vendetta/demon"))
			return notify_fail(wei->name()+"�ȵ���С�ӣ�ɱ���˻�������\n");
		}
	}
	return 1;
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

