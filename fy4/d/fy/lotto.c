inherit ROOM;
#include <ansi.h>

void create()

{
    set("short", HIM"����̨"NOR);
    set("long", @LONG
���治Զ�����Ƿ��Ƴǵ�̽��¥��һ��һ�ȵ����ִ������Ƕ����С���཭
����������Ϊ������֧�ֵ����ɼ���������Ҳ�в����˼���ǽ������Ů�ӵ������
��ע������ǽ������һ���ʾ������������д��Ͷע�����Լ��Ͻ����ִ��
���������Ρ�
LONG
    );
    set("exits", ([ 
	"east": __DIR__"tiandoor",
      ]));
    set("objects", ([
	"/d/bashan/npc/so":1,
	"/d/fy/npc/tatoo.c":1,
	/*		"/d/wiz/obj/betabag":5,
			"/obj/wiz_toy/taskstone": 1,
			"obj/book/class/iceheart_buffup_2":	1,
			"obj/book/class/iceheart_buffup_3":	1,
			"obj/book/class/iceheart_buffup_4":	1,
			"/obj/book/class/qidaoforce_juxue_2":	1,
			"/obj/book/class/qidaoforce_juxue_3":	1,
			"/obj/book/class/essencemagic_team_drift_1":1,
			"/obj/book/class/cloud-dance_yegui_1":	1,		
			"/obj/book/class/cloud-dance_yegui_2":	1,
			"/obj/book/class/cloud-dance_yegui_3":	1,
			"/obj/book/class/dragonstrike_zjbl_2":  1,
			"/obj/book/class/dragonstrike_zjbl_3":  1,
			"/obj/book/class/dragonstrike_zjbl_4":  1,
			"/obj/book/class/xueyeqianzong_feline_2": 1,
			"/obj/book/class/xueyeqianzong_feline_3": 1,
			"/obj/book/class/xueyeqianzong_wolverine_3": 1,
			"/obj/book/class/xuezhan-spear_liguang_1":1,
			"/obj/book/class/xuezhan-spear_liguang_2":1,
			"/obj/book/class/xuezhan-spear_liguang_3":1,
			"/obj/book/class/yijinjing_shield_2": 1,
			"/obj/book/class/yijinjing_shield_3": 1,*/


      ]) );
    set("item_desc", ([
	"sign": @TEXT
==========================================================
Ͷע����

lottolist    ��ѯ���Ѿ�����Ĳ�ȯ����ѯ�´ο���ʱ��
purchase <��Ŀ>   һ��֧��һ��Ǯ������Ϊ��������ȡһЩ��ȯ
checkout     ������һ�ڵĲʽ�

��ȯÿעһ���ƽ�ÿ��Сʱ�Զ�����һ�Σ��뼰ʱ�����н�����㡣

==========================================================
TEXT
      ]) );
    set("coor/x",-20);
    set("coor/y",40);
    set("coor/z",0);
    set("NONPC",1);
    setup();
}


