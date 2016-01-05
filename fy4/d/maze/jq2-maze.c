// silencer@fy4 workgroup 


inherit VRM_SERVER;

void create()
{
	// �Թ��������̳е�����ĵ������ơ�
	set_inherit_room(__DIR__"jq2-room");

	//�Թ��ĳ��Ϳ� (5-100)
	set_maze_long(20,20);
	
	//�趨�Թ���λ�����
	set_maze_spacing(5);

	//�Թ��������npc.
	//note: this one is optional
//	set_maze_npcs(__DIR__"npc/w-sentry-1");

	//�Թ������ڷ��� npc �Ŀ�����(1-100)
	//note: this one is optional too, if not set, then default is 20 (1/5)
//	set_maze_npc_rate(100);

	//�Թ��ؽ�ʱ�� pass in integer ����Ϊ��λ
	//note: this one is optional, if not set then default is no refresh
	//if pass in 0, then means no refresh too.
	// this example means maze will be refreshed in 1 hour.
//	set_maze_refresh(3600);

	//��ڷ���(�����ڶ���)
	set_entry_dir("west");

	//�������������ӷ���
	set_link_entry_dir("west");

	//�������������ӵ�����
	set_link_entry_room(__DIR__"jq2-entry");
	
	//��ڵ�����(��������link_entry_room���Ǹ���ʵroom������
	set_link_entry_room_x(-30);
	set_link_entry_room_y(-15);
	set_link_entry_room_z(-20);
	

	//��������������ӷ���
	set_link_exit_dir("east");

	//��������������ӵ�����
	set_link_exit_room(__DIR__"jq2-exit");

	//��ڷ��������
	set_entry_short("��Ѫ��");

	//��ڷ�������
	set_entry_desc(@LONG
����һ����������������ճճ�����ź�ɫ�����£��ƺ���Ѫ���ƺ����ͣ���
��ʬ��ɢ�䣬����ɫ���׹�����������Щ���ǰ�е�·���˳�����
LONG
);

	//���ڷ��������
	set_exit_short("��Ѫ��");

	//���ڷ�������
	set_exit_desc(@LONG
���εľ�ͷ����һ����������������ճճ�����ź�ɫ�����£��ƺ���Ѫ����
�����ͣ�����ʬ��ɢ�䣬����ɫ���׹�����������Щ���ǰ�е�·���˳�����û��
֪�������Ѻ����˭������ֵ������Ҳֻ������ڴ�ż���������洫������������
��ĲҺ�����
LONG
);

	//�Թ�����Ķ�����
	set_maze_room_short("�����");

	//�Թ����������������ж�������������ÿ����
	//���ʱ���������ѡ��һ����
	set_maze_room_desc(@LONG
������߮�Ź»�Ұ���ķ��ˣ�û�����գ�û�иٳ���û��֪����û����ʶ�� 
ֻ��һ��һ���ɱ¾��ֻ�е���������������������ʱ��ÿһ���Ļ�Ż�֪�� 
����Ҫ��������һ���µ�ʳ���ˮ�Ͳ������Ѷ����ġ����������衻������ 
Ҳֻ��һ�����ڣ�û����֪���Ǹ���̫ͬ���Ͼ�����ɷ���ǵ���������ζ��� 
�ģ�Ī�ǣ����������ˣ�
LONG
);

	// �Թ������Ƿ�Ϊ���ⷿ�䣿
	set_outdoors(0);
}
